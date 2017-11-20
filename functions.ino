void forward () {                     //Forward function for 2 base motors
  Serial.println("forward");
  digitalWrite(dir_R_motor, HIGH);
  analogWrite(E_R_motor, 100);
  digitalWrite(dir_L_motor, HIGH);
  analogWrite(E_L_motor, 100);
}

void backward () {                     //Backward function for 2 base motors
  Serial.println("backward");
  digitalWrite(dir_R_motor, LOW);
  analogWrite(E_R_motor, 100);
  digitalWrite(dir_L_motor, LOW);
  analogWrite(E_L_motor, 100);
}

void left () {                         //Left function for 2 base motors
  Serial.println("left");
  digitalWrite(dir_R_motor, HIGH);
  analogWrite(E_R_motor, 100);
  digitalWrite(dir_L_motor, LOW);
  analogWrite(E_L_motor, 100);
}

void right () {                        /Left function for 2 base motors
  Serial.println("right");
  digitalWrite(dir_R_motor, LOW);
  analogWrite(E_R_motor, 100);
  digitalWrite(dir_L_motor, HIGH);
  analogWrite(E_L_motor, 100);
}

void stoop () {
  Serial.println("stop");
  digitalWrite(E_R_motor, LOW);
  digitalWrite(E_L_motor, LOW);
}

void stteper_down() {
  Serial.println("stteper_down");
  digitalWrite(stepp_dir,LOW);

  for (int i = 0; i < 400; i++) {
    digitalWrite(stepp_stp, HIGH);
    delay(2);
    digitalWrite(stepp_stp, LOW);
  }
  }


void stteper_up() {
  Serial.println("stteper_up");
  digitalWrite(stepp_dir, HIGH);

  for (int i = 0; i < 400; i++) {
    digitalWrite(stepp_stp, HIGH);
    delay(2);
    digitalWrite(stepp_stp, LOW);
  }
}
void piston_up(){
  Serial.println("piston up");
  digitalWrite(uln_2, HIGH);
  delay(10);
  digitalWrite(uln_2, LOW);
  }
 void piston_down(){
  Serial.println("piston down");
  digitalWrite(uln_1, HIGH);
  delay(10);
  digitalWrite(uln_1, LOW);
  }

  void piston_shot(){
  Serial.println("piston shot");
  digitalWrite(uln_3, HIGH);
  delay(500);
  digitalWrite(uln_3, LOW);
  }
void feed(int state)
{
  Serial.println("state= ");
  Serial.println(state);
  //digitalWrite(dir_fd, HIGH);
  digitalWrite(E_fd,state);
}

