#include <hailo/hailort.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>

int main()
{
    auto dev = hailort::Device::scan().expect("Failed getting a device");
    std::cout << dev.size() << std::endl;

    cv::VideoCapture cap(0); // 0 is the default device (Raspberry Pi camera)

    // Check if the camera opened successfully
    if (!cap.isOpened()) {
        std::cerr << "Error: Could not open the camera." << std::endl;
        return -1;
    }

    // Get the frames per second (fps) of the camera
    double fps = cap.get(cv::CAP_PROP_FPS);
    if (fps == 0) {
        std::cout << "Warning: Could not retrieve FPS, using default (30)." << std::endl;
        fps = 30.0;
    }

    // Frame container
    cv::Mat frame;

    // Capture and display video frames
    while (true) {
        // Capture a frame from the camera
        cap >> frame;

        // Check if the frame is empty (end of video)
        if (frame.empty()) {
            std::cerr << "Error: Could not grab a frame." << std::endl;
            break;
        }

        // Display the frame
        cv::imshow("Video Stream", frame);

        // Wait for 'q' key to exit
        if (cv::waitKey(1000 / fps) == 'q') {
            break;
        }
    }

    // Release the camera and close the display window
    cap.release();
    cv::destroyAllWindows();

    return 0;
}