int col_left[] = {0,1,2,3};
int row_left[] = {A0,A1,A2,A3};
int col_right[] = {4,5,6,7};
int row_right[] = {A4,A5,8,9};
int dip_switch[] = {10,11,12,13};

void sad(){
  int j = 3;
  for(int i=0;i<=3;i++){
    digitalWrite(row_left[i],HIGH);
    digitalWrite(row_right[i],HIGH);
    digitalWrite(col_left[i],LOW);
    digitalWrite(col_right[j],LOW);
    
    delay(10);
    digitalWrite(row_left[i],LOW);
    digitalWrite(row_right[i],LOW);
    digitalWrite(col_left[i],HIGH);
    digitalWrite(col_right[j],HIGH);
    j--;
  }
}
void mad(){
  int j = 3;
  for(int i=0;i<=3;i++){
    digitalWrite(row_left[i],HIGH);
    digitalWrite(row_right[i],HIGH);
    digitalWrite(col_left[j],LOW);
    digitalWrite(col_right[i],LOW);
    
    delay(10);
    digitalWrite(row_left[i],LOW);
    digitalWrite(row_right[i],LOW);
    digitalWrite(col_left[j],HIGH);
    digitalWrite(col_right[i],HIGH);
    j--;
  }
}
void dead(){
  int j = 3;
  for(int i=0;i<=3;i++){
    digitalWrite(row_left[i],HIGH);
    digitalWrite(row_right[i],HIGH);
    digitalWrite(col_left[j],LOW);
    digitalWrite(col_right[i],LOW);
    delay(10);
    digitalWrite(row_left[i],LOW);
    digitalWrite(row_right[i],LOW);
    digitalWrite(col_left[j],HIGH);
    digitalWrite(col_right[i],HIGH);
    j--;
  } 
  j = 3;
  for(int i=0;i<=3;i++){
    digitalWrite(row_left[i],HIGH);
    digitalWrite(row_right[i],HIGH);
    digitalWrite(col_left[i],LOW);
    digitalWrite(col_right[j],LOW);
    delay(10);
    digitalWrite(row_left[i],LOW);
    digitalWrite(row_right[i],LOW);
    digitalWrite(col_left[i],HIGH);
    digitalWrite(col_right[j],HIGH);
    j--;
  } 
}
void sleepy(){
  //first_line
  for(int i=3;i>=0;i--){
    digitalWrite(row_left[0],HIGH);
    digitalWrite(row_right[0],HIGH);   
    digitalWrite(col_left[i],LOW);
    digitalWrite(col_right[i],LOW);
    delay(10);
    digitalWrite(col_left[i],HIGH);
    digitalWrite(col_right[i],HIGH);
  }
  //sad_diagonal
  for(int i=0;i<=3;i++){
    digitalWrite(row_left[i],HIGH);
    digitalWrite(row_right[i],HIGH);
    digitalWrite(col_left[i],LOW);
    digitalWrite(col_right[i],LOW);
    delay(10);
    digitalWrite(row_left[i],LOW);
    digitalWrite(row_right[i],LOW);
    digitalWrite(col_left[i],HIGH);
    digitalWrite(col_right[i],HIGH);
   }
  //last_line
  for(int i=3;i>=0;i--){
    digitalWrite(row_left[3],HIGH);
    digitalWrite(row_right[3],HIGH);
    digitalWrite(col_left[i],LOW);
    digitalWrite(col_right[i],LOW);
    delay(10);
    digitalWrite(col_left[i],HIGH);
    digitalWrite(col_right[i],HIGH);
  }
  //clears
  for(int i=0;i<=3;i++){
    digitalWrite(row_left[i],LOW);
    digitalWrite(row_right[i],LOW);
    digitalWrite(col_left[i],HIGH);
    digitalWrite(col_right[i],HIGH);
  }
}
void wtf(){
  for(int i=3;i>=0;i--){
    digitalWrite(row_left[1],HIGH);
    digitalWrite(row_right[1],HIGH);   
    digitalWrite(row_left[2],HIGH);
    digitalWrite(row_right[2],HIGH);  
    digitalWrite(col_left[i],LOW);
    digitalWrite(col_right[i],LOW);
    delay(10);
    digitalWrite(col_left[i],HIGH);
    digitalWrite(col_right[i],HIGH);
  }
}
void clear(){
  for(int i=0;i<=3;i++){
    digitalWrite(row_left[i],LOW);
    digitalWrite(row_right[i],LOW);
    digitalWrite(col_left[i],HIGH);
    digitalWrite(col_right[i],HIGH);
  }
}
void setup() {
  for(int i=0;i<=3;i++){
    pinMode(col_left[i],OUTPUT);
    pinMode(row_left[i],OUTPUT);
    pinMode(col_right[i],OUTPUT);
    pinMode(row_right[i],OUTPUT);
    digitalWrite(col_left[i],HIGH);
    digitalWrite(row_left[i],LOW);
    digitalWrite(col_right[i],HIGH);
    digitalWrite(row_right[i],LOW);
   }
   for(int i=0;i<=3;i++){
    pinMode(dip_switch[i],INPUT_PULLUP);
   }
}

void loop() {
  int sads = digitalRead(dip_switch[0]);
  int mads = digitalRead(dip_switch[1]);
  int deads = digitalRead(dip_switch[2]);
  int sleepys = digitalRead(dip_switch[3]);

  if((sads == HIGH) && (mads == LOW) && (deads == LOW) && (sleepys == LOW))
    sad();
  if((sads == LOW) && (mads == HIGH) && (deads == LOW) && (sleepys == LOW))
    mad();
  if((sads == LOW) && (mads == LOW) && (deads == HIGH) && (sleepys == LOW))
    dead();
  if((sads == LOW) && (mads == LOW) && (deads == LOW) && (sleepys == HIGH))
    sleepy();
  if((sads == LOW) && (mads == HIGH) && (deads == HIGH) && (sleepys == LOW))
    wtf();
}
