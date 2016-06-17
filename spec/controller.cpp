
TEST(Controller, Broadcast) {
  Controller c;
  TestModule* a = new TestModule(&c);
  TestModule* b = new TestModule(&c);
  c.addModule(a);
  c.addModule(b);
  Message* m = new Message(0, "TestMessage");
  c.broadcast(m);

  EXPECT_EQ(a->m.size(), 1);
  EXPECT_EQ(b->m.size(), 1);

  if(a->m.size()) EXPECT_EQ((a->m[0])->body, "TestMessage");
  if(b->m.size()) EXPECT_EQ((b->m[0])->body, "TestMessage");
}
