
class Test_Module:public Module{
public:
  void test_broadcast(Message* message){
    broadcast(message);
  }

  Message* test_getMessges(){
    return messages.readMessages();
  }

};

TEST(Module, Broadcast) {
    Test_Module mod;
    Message a(1, "Howdy!");
    Message b(2, "Hiya");
    Message c(3, "Hola");

    mod.test_broadcast(&a);
    mod.test_broadcast(&b);
    mod.test_broadcast(&c);

    Message* aa = mod.test_getMessges();
    Message* bb = aa->next;
    Message* cc = bb->next;

    ASSERT_TRUE(aa);
    ASSERT_TRUE(bb);
    ASSERT_TRUE(cc);

    EXPECT_EQ(aa->action, 1);
    EXPECT_EQ(cc->body, "Hola");
    EXPECT_EQ(cc->next, (Message*)NULL);
}

TEST(Module, read){
    Test_Module mod;
    Message a(1, "Howdy!");
    Message b(2, "Hiya");
    Message c(3, "Hola");

    mod.test_broadcast(&a);
    mod.test_broadcast(&b);
    mod.test_broadcast(&c);

    Message* aa = mod.read();
    Message* bb = aa->next;
    Message* cc = bb->next;

    ASSERT_TRUE(aa);
    ASSERT_TRUE(bb);
    ASSERT_TRUE(cc);

    EXPECT_EQ(aa->action, 1);
    EXPECT_EQ(cc->body, "Hola");
    EXPECT_EQ(cc->next, (Message*)NULL);
    EXPECT_EQ(mod.read(), (Message*)NULL);

}

TEST(Module, ModuleTask){
  // Test_Module mod; TODO figure out good way
  // Message message(1, "done");
  // mod.runTask(test_task, &message);
  // // sleep(1);
  //
  // Message* done = mod.test_getMessges();
  //
  // ASSERT_TRUE(done);
  // ASSERT_EQ(done->action, 1);
  // ASSERT_EQ(done->body, "done");
}
