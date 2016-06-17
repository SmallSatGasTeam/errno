
class TestController: public Controller{
public:
  bool broadcast(Message* message){
    m.push_back(message);
    return 1;
  }

  std::vector<Message*> m;
};


TEST(Module, Broadcast) {
    TestController testControl;
    Module mod(&testControl);
    Message message(EXAMPLE_ACTION, "greeting:Howdy!");
    // mod.broadcast(&message); TODO implement Mocking
    // ASSERT_EQ(testControl.m.size(), 1);
}
