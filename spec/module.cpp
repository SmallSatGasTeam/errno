TEST(Module, Broadcast) {
    Module mod;
    Message message(EXAMPLE_ACTION, "greeting:Howdy!");
    // mod.broadcast(&message); TODO implement Mocking
    // ASSERT_EQ(testControl.m.size(), 1);
}

void test_task(){
  sleep(1);
  exit(0);
}

TEST(Module, ModuleTask){
  Module mod;
  Message message(EXAMPLE_ACTION, "status:Test Task Done");
  mod.runTask(test_task, &message);
  sleep(2);

  std::vector<Message*> messages = mod.read();
  ASSERT_EQ(messages[0]->action, EXAMPLE_ACTION);
  ASSERT_EQ(messages[0]->body, "status:Test Task Done");
}
