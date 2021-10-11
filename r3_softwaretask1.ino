// C++ code
//

int left_0 = 2;
int left_1 = 3;
int left_2 = 4;
int left_3 = 5;

int right_0 = 6;
int right_1 = 7;
int right_2 = 8;
int right_3 = 9;

int sensor_input = 0;

int first_digit = 0;
int second_digit = 0;

void setup()
{
  //left digit connection to arduino
  pinMode(left_0, OUTPUT);
  pinMode(left_1, OUTPUT);
  pinMode(left_2, OUTPUT);
  pinMode(left_3, OUTPUT);
  
  //right digit connection to arduino
  pinMode(right_0, OUTPUT);
  pinMode(right_1, OUTPUT);
  pinMode(right_2, OUTPUT);
  pinMode(right_3, OUTPUT);
  
  pinMode(A0, INPUT);
}

// 0 for left, 1 for right
void toBinary(int display, int num)
{
  //check which 7seg to display to
  if (display == 0)
  {
    //convert to binary for CD4511
    switch (num)
    {
      	case 0:
      	digitalWrite(left_3, 0);
      	digitalWrite(left_2, 0);
      	digitalWrite(left_1, 0);
      	digitalWrite(left_0, 0);
      	break;
        
      	case 1:
      	digitalWrite(left_3, 0);
      	digitalWrite(left_2, 0);
      	digitalWrite(left_1, 0);
      	digitalWrite(left_0, 1);
      	break;
      
        case 2:
      	digitalWrite(left_3, 0);
      	digitalWrite(left_2, 0);
      	digitalWrite(left_1, 1);
      	digitalWrite(left_0, 0);
      	break;
      
        case 3:
      	digitalWrite(left_3, 0);
      	digitalWrite(left_2, 0);
      	digitalWrite(left_1, 1);
      	digitalWrite(left_0, 1);
      	break;
      
        case 4:
      	digitalWrite(left_3, 0);
      	digitalWrite(left_2, 1);
      	digitalWrite(left_1, 0);
      	digitalWrite(left_0, 0);
      	break;
      
        case 5:
      	digitalWrite(left_3, 0);
      	digitalWrite(left_2, 1);
      	digitalWrite(left_1, 0);
      	digitalWrite(left_0, 1);
      	break;
      
        case 6:
      	digitalWrite(left_3, 0);
      	digitalWrite(left_2, 1);
      	digitalWrite(left_1, 1);
      	digitalWrite(left_0, 0);
      	break;
      
        case 7:
      	digitalWrite(left_3, 0);
      	digitalWrite(left_2, 1);
      	digitalWrite(left_1, 1);
      	digitalWrite(left_0, 1);
      	break;
      
        case 8:
      	digitalWrite(left_3, 1);
      	digitalWrite(left_2, 0);
      	digitalWrite(left_1, 0);
      	digitalWrite(left_0, 0);
      	break;
      
        case 9:
      	digitalWrite(left_3, 1);
      	digitalWrite(left_2, 0);
      	digitalWrite(left_1, 0);
      	digitalWrite(left_0, 1);
      	break;
    } 
  } else if (display == 1)
  {
    //convert to binary for CD4511
    switch (num)
    {
      	case 0:
      	digitalWrite(right_3, 0);
      	digitalWrite(right_2, 0);
      	digitalWrite(right_1, 0);
      	digitalWrite(right_0, 0);
      	break;
        
      	case 1:
      	digitalWrite(right_3, 0);
      	digitalWrite(right_2, 0);
      	digitalWrite(right_1, 0);
      	digitalWrite(right_0, 1);
      	break;
      
        case 2:
      	digitalWrite(right_3, 0);
      	digitalWrite(right_2, 0);
      	digitalWrite(right_1, 1);
      	digitalWrite(right_0, 0);
      	break;
      
        case 3:
      	digitalWrite(right_3, 0);
      	digitalWrite(right_2, 0);
      	digitalWrite(right_1, 1);
      	digitalWrite(right_0, 1);
      	break;
      
        case 4:
      	digitalWrite(right_3, 0);
      	digitalWrite(right_2, 1);
      	digitalWrite(right_1, 0);
      	digitalWrite(right_0, 0);
      	break;
      
        case 5:
      	digitalWrite(right_3, 0);
      	digitalWrite(right_2, 1);
      	digitalWrite(right_1, 0);
      	digitalWrite(right_0, 1);
      	break;
      
        case 6:
      	digitalWrite(right_3, 0);
      	digitalWrite(right_2, 1);
      	digitalWrite(right_1, 1);
      	digitalWrite(right_0, 0);
      	break;
      
        case 7:
      	digitalWrite(right_3, 0);
      	digitalWrite(right_2, 1);
      	digitalWrite(right_1, 1);
      	digitalWrite(right_0, 1);
      	break;
      
        case 8:
      	digitalWrite(right_3, 1);
      	digitalWrite(right_2, 0);
      	digitalWrite(right_1, 0);
      	digitalWrite(right_0, 0);
      	break;
      
        case 9:
      	digitalWrite(right_3, 1);
      	digitalWrite(right_2, 0);
      	digitalWrite(right_1, 0);
      	digitalWrite(right_0, 1);
      	break;
    }
  }
  
}

void loop()
{
  //get reading from potentiometer
  sensor_input = analogRead(A0);
  sensor_input = (sensor_input / 1023.0) * 100.0;
  
  if (sensor_input != 100)
  {
  first_digit = sensor_input / 10;
  second_digit = sensor_input - (first_digit * 10);

  toBinary(0, first_digit);
  toBinary(1, second_digit);
  } else {
    toBinary(0, 9);
    toBinary(1, 9);
  }
  
}
