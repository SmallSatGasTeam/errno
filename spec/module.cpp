TEST(Module, Broadcast) {
    TestController testControl;
    Module mod(&testControl);
    Message message(EXAMPLE_ACTION, "greeting:Howdy!");
    // mod.broadcast(&message); TODO implement Mocking
    // ASSERT_EQ(testControl.m.size(), 1);
}
