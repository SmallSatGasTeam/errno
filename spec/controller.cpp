
TEST(Controller, Broadcast) {
  Controller c;
  TestModule a;
  TestModule b;
  c.addModule(&a);
  c.addModule(&b);
  Message m(0, "TestMessage");
  c.broadcast(&m);

  Message* a_message = a->read();
  Message* b_message = b->read();

  ASSERT_TRUE(a_message);
  ASSERT_TRUE(b_message);
  EXPECT_EQ(a_message->action, 0);
  EXPECT_EQ(b_message->action, 0);
  EXPECT_EQ(a_message->body, "TestMessage");
  EXPECT_EQ(b_message->body, "TestMessage");
}

TEST(Controller, Read_Modules) {
  Controller c;
  TestModule a;
  TestModule b;

  Message m(1, "TestMessage");
  c.addModule(&a);
  c.addModule(&b);
  c.broadcast(&m);
  c.readModules();

  Message* messages = c.getMessages();
  // EXPECT_EQ(messages.size(), 3);
  // if(messages.size()) EXPECT_EQ(messages[0]->action, 1);
}
