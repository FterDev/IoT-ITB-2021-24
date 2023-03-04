class WaterLevelSens
{
    // user-accessible "public" interface
  public:
	WaterLevelSens();
    //Initialize parameters such as I2C address and port for communication
	boolean begin(uint8_t address = 0x28, TwoWire &wirePort = Wire);//If user doesn't specificy then 0x28 and Wire will be used
	
	//Test I2C connection on I2C address
	boolean isConnected();

	//Returns value between 0 and 1023 (raw sensor reading)
	uint16_t getAdcValue();

	//Returns value between 0 and 100 based on limits
	uint8_t getPercentageValue(); 

	//Turn LED on Sensor ON or OFF
	void ledOn();
	void ledOff();

	//Calibrate system by setting "dry" (0%) soil moisture value
	void setUpperAdcLimit(uint16_t value);

  private:
	//This stores the current I2C address of the LED Stick
	uint8_t _soilSensAddress;
	//This stores the requested i2c port
	TwoWire * _i2cPort;

	uint16_t _upperAdcLimit; //Represents 0% soil moisture

	uint16_t _lowerAdcLimit; //Represents 100% soil moisture
}; 

#endif