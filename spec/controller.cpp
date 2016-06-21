
TEST(Controller, Broadcast) {
  Controller c;
  TestModule* a = new TestModule();
  TestModule* b = new TestModule();
  c.addModule(a);
  c.addModule(b);
  Message* m = new Message(0, "TestMessage");
  c.broadcast(m);

  EXPECT_EQ(a->m.size(), 1);
  EXPECT_EQ(b->m.size(), 1);

  if(a->m.size()) EXPECT_EQ((a->m[0])->body, "TestMessage");
  if(b->m.size()) EXPECT_EQ((b->m[0])->body, "TestMessage");
}

TEST(Controller, Read_Modules) {
  Controller c;
  TestModule* a = new TestModule();
  TestModule* b = new TestModule();

  Message* m = new Message(1, "TestMessage");
  c.addModule(a);
  c.addModule(b);
  c.broadcast(m);
  c.readModules();

  std::vector<Message*> messages = c.getMessages();
  EXPECT_EQ(messages.size(), 3);
  if(messages.size()) EXPECT_EQ(messages[0]->action, 1);
}
