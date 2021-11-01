char commandReceived;
char commandSent;

int rightSpeedFWD = 0;
int leftSpeedFWD = 0;
int rightSpeedBWD = 0;
int leftSpeedBWD = 0;

bool releaseBreakes = true;
bool pathBlocked = false;

int acelerationStep = 5;
int deacelerationStep = 5;

int currentDirection = 0;
int lastDirection = 0;
bool keepTurning = true;

long setTimer;
