TEST(MessageList, addMessage) {
  MessageList list;
  Message a(1, "Howdy");
  Message b(2, "Hola");
  Message c(3, "Oi");

  list.addMessage(&a);
  list.addMessage(&b);
  list.addMessage(&c);

  Message* aa = list.readMessages();
  Message* bb = aa->next;
  Message* cc = bb->next;

  ASSERT_TRUE(aa);
  EXPECT_EQ(aa->action, 1);
  EXPECT_EQ(aa->body, "Howdy");
  EXPECT_EQ(cc->action, 3);
  EXPECT_EQ(cc->body, "Oi");
  EXPECT_EQ(cc->next, (Message*)NULL);
  EXPECT_EQ(list.readMessages(), (Message*)NULL);
}
