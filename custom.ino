void setup_custom_init() {
  setup_stepper(); //pentru a elibera motorul, este foarte important să îl faceți imediat
}

void setup_custom() {
  setup_stepper(); //inițializați din nou motorul, setările sunt deja de la eeprom
  send_status(); //trimite status imediat
}

void loop_custom() {  
  loop_stepper();
}

void send_status() {
  //mqttPublish("progress/state", String(STEPPER_STATE)); //statutul de trimitere este inutil, va exista întotdeauna 0
  
  send_status_position();
}

void send_status_position() {
  mqttPublishRetained("position/percent", String(positionToPercentStrict(abs(STEPPER_POSITION))));
  if (STEPPER_STATE==0) {
    mqttPublish("position/target", String(positionToPercentStrict(abs(STEPPER_TARGET))));
  }
  //mqttPublish("meta/stepper/current_rpm", String(stepper.getCurrentRPM()));
}
