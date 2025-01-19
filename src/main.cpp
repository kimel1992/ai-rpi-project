#include <hailo/hailort.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>


std::string get_pipeline_str() {
    // Get the value of the environment variable "RESOLUTION"
    auto resolution = std::getenv("CAM_RES");

    // Default resolution values
    uint32_t width = 640;
    uint32_t height = 480;

    // Modify the resolution based on the value of the environment variable
    if (resolution != nullptr) {
        if (std::string(resolution) == "HD") {
            width = 1280;
            height = 720;
        } else if (std::string(resolution) == "FHD") {
            width = 1920;
            height = 1080;
        }
    }

    // Construct and return the pipeline string with the appropriate resolution
    return "libcamerasrc ! video/x-raw,width=" + std::to_string(width) + 
           ",height=" + std::to_string(height) + ",format=BGR ! videoconvert ! appsink";
}

int main()
{
    auto pipeline_str = get_pipeline_str();

    // Open the video capture from the camera (0 for default webcam)
    cv::VideoCapture cap(pipeline_str);

    // Check if the camera is opened
    if (!cap.isOpened()) {
        std::cerr << "Error: Could not open camera!" << std::endl;
        return -1;
    }

    try {
        auto dev = hailort::Device::scan().expect("Failed getting a device");
        std::cout << dev.size() << std::endl;

        // Create a Mat object to hold the frames
        cv::Mat frame;

        // Loop to capture and display frames
        while (true) {
            // Capture the frame
            cap >> frame;

            // Check if the frame is valid
            if (frame.empty()) {
                std::cerr << "Error: Could not grab frame!" << std::endl;
                break;
            }

            // Display the frame in a window
            cv::imshow("Camera Feed", frame);

            // Wait for 1 ms and check if the user pressed the 'Esc' key (key code 27)
            char key = cv::waitKey(1);
            if (key == 27) {
                break; // Exit the loop if 'Esc' is pressed
            }
        }
    } catch (const std::exception &exception) {
        std::cout << "Cauget an exception - " << exception.what() << std::endl;
    };

    // Release the camera and close all windows
    cap.release();
    cv::destroyAllWindows();
    return 0;
}