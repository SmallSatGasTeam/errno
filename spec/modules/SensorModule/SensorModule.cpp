class Test_SensorModule:public SensorModule{
public:
  std::string test_readSensors(){
    return this->readSensors();
  }
};

TEST(SensorModule, ReadSensors){
  Test_SensorModule mod;
  TestSensor s1;
  TestSensor s2;
  TestSensor s3;
  mod.addSensor(&s1);
  mod.addSensor(&s2);
  mod.addSensor(&s3);
  std::string message = mod.test_readSensors();
  ASSERT_EQ(message, "TestReading,TestReading,TestReading,");
}
