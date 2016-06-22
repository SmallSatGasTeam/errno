TEST(CameraModule, it_lives) {
    CameraModule mod;
    ASSERT_EQ(mod.status(), false);
}

// TEST(CameraModule, take_photo) {
//     CameraModule mod;
//     mod.takePhoto();
//     sleep(2); // Wait for asynchronous process to finish
//
//     std::vector<Message*> messages = mod.read();
//
//     ASSERT_EQ(messages.size(), 1);
//     if(messages.size()) ASSERT_EQ(messages[0]->action, PHOTO_TAKEN);
// }
