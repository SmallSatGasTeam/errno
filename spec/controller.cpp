
TEST(Controller, Broadcast) {
  Controller c;
  TestModule a;
  TestModule b;
  c.addModule(&a);
  c.addModule(&b);
  Message m(0, "TestMessage");
  c.broadcast(&m);

  Message* a_message = a.test_getBroadcastMessage();
  Message* b_message = b.test_getBroadcastMessage();

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

  Message* aa = c.getMessages();
  Message* bb = aa->next;
  Message* cc = bb->next;

  ASSERT_TRUE(aa);
  ASSERT_TRUE(bb);
  ASSERT_FALSE(cc);

  EXPECT_EQ(aa->body, "TestMessage");
  EXPECT_EQ(bb->body, "TestMessage");
}
