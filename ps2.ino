void main()
{
  if (error == 1)        //skip loop if no controller found
    return;
  if (type == 2) {       //DualShock Controller
    
    if (!((ps2x.Button(PSB_PAD_UP) || (ps2x.Button(PSB_PAD_RIGHT)) || (ps2x.Button(PSB_PAD_LEFT)) || (ps2x.Button(PSB_PAD_DOWN))|| (ps2x.Button(PSB_START))))) {
      stoop(); //stop base motors and solenoid
    }
    ps2x.read_gamepad(false, vibrate);          //read controller and set large motor to spin at 'vibrate' speed
    if (ps2x.ButtonPressed(PSB_START))
    {
      Serial.println("Start is being held");
      state=!state;
      feed(state);
    }
    if (ps2x.ButtonPressed(PSB_SELECT))
    {
      Serial.println("Select is being held");
      piston_shot();
    }
    if (ps2x.Button(PSB_PAD_UP)) {        //Mapping of pins to motion functions of the base
      forward();
    }
    if (ps2x.Button(PSB_PAD_RIGHT)) {
      right();
    }
    if (ps2x.Button(PSB_PAD_LEFT)) {
      left();
    }
    if (ps2x.Button(PSB_PAD_DOWN)) {
      backward();
    }
    if (ps2x.ButtonPressed(PSB_R1))        //Increases the speed of brushless motors
    {
      Serial.println("R1 pressed");
      signal1 += 5;
      signal1 = constrain(signal1, 90, 180);
       Serial.println("signal1=");
       Serial.println(signal1);
    }
    if (ps2x.ButtonPressed(PSB_L1))        //Decreases the speed of brushless motors
    {
      Serial.println("L1 pressed");
      signal1 -= 5;
      signal1 = constrain(signal1, 90, 180);
       Serial.println("signal1=");
       Serial.println(signal1);
    }
    if (ps2x.Button(PSB_R1) && ps2x.Button(PSB_L1))   //Turning of the forward brushless motor
    {
      signal1 = 90;
      Serial.println("brushless_f  off");
       Serial.println("signal1=");
       Serial.println(signal1);
    }
    if (ps2x.ButtonPressed(PSB_R2))                 //Increases the speed of brushless motors                    
    {
      Serial.println("L2 pressed");
      signal2 += 5;
      signal2 = constrain(signal2, 90, 180);
       Serial.println("signal2=");
       Serial.println(signal2);
    }
    if (ps2x.ButtonPressed(PSB_L2))                   //Decreases the speed of brushless motors
    {
      Serial.println("R2 pressed");
      signal2 -= 5;
       Serial.println("signal2=");
       Serial.println(signal2);

    }
    if (ps2x.Button(PSB_R2) && ps2x.Button(PSB_L2))       //Turning of the backward brushless motor
    {
      signal2 = 90;
      Serial.println("brushless_b  off");
       Serial.println("signal1=");
       Serial.println(signal1);
    }
    if (ps2x.ButtonPressed(PSB_GREEN))                    //seting the pin for solenoid HIGH
    {
      Serial.println("Triangle pressed");
      piston_up();
    }
    
    if (ps2x.ButtonPressed(PSB_BLUE))                     //seting the pin for solenoid LOW
    {
      Serial.println("X just pressed");
      piston_down();
    }
    
    if (ps2x.ButtonPressed(PSB_RED))   
    {
      Serial.println("Circle just pressed");
       stteper_up(); 

    }
     if(ps2x.ButtonPressed(PSB_PINK)) 
     {
      Serial.println("Square just pressed");
      stteper_down();

    }
  
    delay(50);
  }
  esc_forw.write(signal1);                          //Writing the finals values to the ESCs
  esc_back.write(signal2);
}

