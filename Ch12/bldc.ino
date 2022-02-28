/* This sketch controls a BLDC by applying voltage to the
   six switches on the ESC Shield discussed in Chapter 12 */

// Assign names to the pins
int i, t, va, vp;
int old_time, zc_interval;
int ctrl_ah = 13;
int ctrl_al = 12;
int ctrl_bh = 11;
int ctrl_bl = 10;
int ctrl_ch = 9;
int ctrl_cl = 8;
int zc_a = 0;
int zc_b = 1;
int zc_c = 2;
int zc_p = 3;

int time_goal = 50;

void setup() {
  
  // Bring rotor to a known initial position
  for (i=0; i<255; i+=5){
    analogWrite(ctrl_ah, i);
    analogWrite(ctrl_bl, i);
    analogWrite(ctrl_cl, i);    
    delay(60);                  
  }
  
  // Set initial timing value
  old_time = millis();
  
  // Start turning the rotor slowly
  for (t=500; t>200; t-=50) {
    rotate(t);
  }
  t = 200;
}

void loop() { 
  
  // Check for zero-crossing
  vp = analogRead(zc_p);
  va = analogRead(zc_a);
  if((vp - va < 10) || (va - vp < 10)) {
    zc_interval = millis() - old_time;
    old_time = millis();
    if(zc_interval - time_goal > 50) {
      t -= 25;
    }
    else if(time_goal - zc_interval > 50) {
      t += 25;
    }
  }
  
  // Rotate the BLDC
  rotate(t);
}

// Rotate the motor at the given value of t
void rotate(int t) {
  digitalWrite(ctrl_ah, HIGH);
  digitalWrite(ctrl_al, LOW);  
  digitalWrite(ctrl_bh, LOW);    
  digitalWrite(ctrl_bl, HIGH);
  digitalWrite(ctrl_ch, LOW);    
  digitalWrite(ctrl_cl, LOW);
  delay(t);
  
  digitalWrite(ctrl_ah, HIGH);
  digitalWrite(ctrl_al, LOW);  
  digitalWrite(ctrl_bh, LOW);    
  digitalWrite(ctrl_bl, LOW);
  digitalWrite(ctrl_ch, LOW);    
  digitalWrite(ctrl_cl, HIGH);
  delay(t); 
  
  digitalWrite(ctrl_ah, LOW);
  digitalWrite(ctrl_al, LOW);  
  digitalWrite(ctrl_bh, HIGH);    
  digitalWrite(ctrl_bl, LOW);
  digitalWrite(ctrl_ch, LOW);    
  digitalWrite(ctrl_cl, HIGH);
  delay(t);   
  
  digitalWrite(ctrl_ah, LOW);
  digitalWrite(ctrl_al, HIGH);  
  digitalWrite(ctrl_bh, HIGH);    
  digitalWrite(ctrl_bl, LOW);
  digitalWrite(ctrl_ch, LOW);    
  digitalWrite(ctrl_cl, LOW);
  delay(t);
  
  digitalWrite(ctrl_ah, LOW);
  digitalWrite(ctrl_al, HIGH);  
  digitalWrite(ctrl_bh, LOW);    
  digitalWrite(ctrl_bl, LOW);
  digitalWrite(ctrl_ch, HIGH);    
  digitalWrite(ctrl_cl, LOW);
  delay(t); 
  
  digitalWrite(ctrl_ah, LOW);
  digitalWrite(ctrl_al, LOW);  
  digitalWrite(ctrl_bh, LOW);    
  digitalWrite(ctrl_bl, HIGH);
  digitalWrite(ctrl_ch, HIGH);    
  digitalWrite(ctrl_cl, LOW);
  delay(t);   
}