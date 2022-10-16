#define encoder 2

int pre_state = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(encoder, INPUT);
}

void loop()
{ 
  int cur_state = digitalRead(encoder);
  if(pre_state == 0 && cur_state == 1){
    Serial.println("Rising!");
    }
  pre_state = cur_state;
}