TEST(CameraModule, it_lives) {
    TestController testControl;
    CameraModule mod(&testControl);
    ASSERT_EQ(mod.status(), 1);
}
