char commandReceived;
char commandSent;

float currentVoltage = 0;

int rightSpeedFWD = 0;
int leftSpeedFWD = 0;
int rightSpeedBWD = 0;
int leftSpeedBWD = 0;

bool releaseBreakes = true;

bool movement[] = {false, false, false}; //fwd ~ bkwd

int acelerationStep = 5;
