void pin_def ()
{
  pinMode(dir_R_motor, OUTPUT);
  pinMode(E_R_motor, OUTPUT);
  pinMode(dir_L_motor, OUTPUT);
  pinMode(E_L_motor, OUTPUT);
  pinMode(dir_fd, OUTPUT);
  pinMode(E_fd, OUTPUT);
  pinMode(uln_1, OUTPUT);
  pinMode(uln_2, OUTPUT);
  pinMode(uln_3, OUTPUT);
  pinMode(uln_4, OUTPUT);
  pinMode(stepp_dir, OUTPUT);
  pinMode(stepp_stp, OUTPUT);
  esc_forw.attach(43);             //forward brushless motor                                                                                                                                                                   one
  esc_back.attach(45);             //backward brushless motor
  lcd.begin(16, 2);
  
}

