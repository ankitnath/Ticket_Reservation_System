#include "gui.hpp"

#include "imgui.h"
#include "backends/imgui_impl_glfw.h"
#include "backends/imgui_impl_opengl3.h"
#include <GLFW/glfw3.h>

#include <iostream>
#include <string>

static void glfw_error_callback(int error, const char* description) {
    std::cerr << "GLFW Error " << error << ": " << description << std::endl;
}

void run_gui(ReservationSystem& system) {
    // Initialize GLFW
    glfwSetErrorCallback(glfw_error_callback);
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW\n";
        return;
    }

#if __APPLE__
    const char* glsl_version = "#version 150";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#else
    const char* glsl_version = "#version 130";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
#endif

    GLFWwindow* window = glfwCreateWindow(800, 600, "Ticket Reservation GUI", nullptr, nullptr);
    if (window == nullptr) {
        std::cerr << "Failed to create GLFW window\n";
        glfwTerminate();
        return;
    }
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1); // Enable vsync

    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();

    ImGuiIO& io = ImGui::GetIO(); (void)io;

    ImGui::StyleColorsDark();

    // Setup Platform/Renderer bindings
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init(glsl_version);

    // Variables for GUI state
    static int menuChoice = 0; // 0 = none, 1=Display, 2=Book, 3=Cancel, 4=Show booked, 5=Exit
    static int seatNumberInput = 1;
    static char passengerNameInput[128] = "";
    static std::string message = "";

    // Main loop
    while (!glfwWindowShouldClose(window) && menuChoice != 5) {
        glfwPollEvents();

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        ImGui::Begin("Ticket Reservation System");

        // Show menu buttons
        ImGui::Text("Menu:");
        if (ImGui::Button("1. Display Seats")) {
            menuChoice = 1;
            message.clear();
        }
        ImGui::SameLine();
        if (ImGui::Button("2. Book Seat")) {
            menuChoice = 2;
            message.clear();
        }
        ImGui::SameLine();
        if (ImGui::Button("3. Cancel Booking")) {
            menuChoice = 3;
            message.clear();
        }
        ImGui::SameLine();
        if (ImGui::Button("4. Show Booked Seats")) {
            menuChoice = 4;
            message.clear();
        }
        ImGui::SameLine();
        if (ImGui::Button("5. Exit")) {
            menuChoice = 5;
        }

        ImGui::Separator();

        // Handle choices
        if (menuChoice == 1) {
            ImGui::Text("Seat Availability:");
            auto& seats = system.getAllSeats();
            for (const auto& seat : seats) {
                ImGui::Text("Seat %d - %s", seat.seatNumber, seat.isBooked ? ("Booked by " + seat.passengerName).c_str() : "Available");
            }
        }
        else if (menuChoice == 2) {
            ImGui::Text("Book a Seat:");

            ImGui::InputInt("Seat number", &seatNumberInput);
            ImGui::InputText("Passenger name", passengerNameInput, IM_ARRAYSIZE(passengerNameInput));

            if (ImGui::Button("Book")) {
                bool success = system.bookSeat(seatNumberInput, std::string(passengerNameInput));
                if (success) {
                    message = "Seat " + std::to_string(seatNumberInput) + " successfully booked for " + std::string(passengerNameInput) + "!";
                } else {
                    message = "Booking failed: Seat invalid or already booked.";
                }
            }
            if (!message.empty()) {
                ImGui::TextWrapped("%s", message.c_str());
            }
        }
        else if (menuChoice == 3) {
            ImGui::Text("Cancel Booking:");

            ImGui::InputInt("Seat number to cancel", &seatNumberInput);

            if (ImGui::Button("Cancel")) {
                bool success = system.cancelBooking(seatNumberInput);
                if (success) {
                    message = "Booking cancelled for seat " + std::to_string(seatNumberInput) + ".";
                } else {
                    message = "Cancellation failed: Seat invalid or not booked.";
                }
            }
            if (!message.empty()) {
                ImGui::TextWrapped("%s", message.c_str());
            }
        }
        else if (menuChoice == 4) {
            ImGui::Text("Booked Seats Summary:");
            auto bookedSeats = system.getBookedSeats();
            if (bookedSeats.empty()) {
                ImGui::Text("No seats booked yet.");
            } else {
                for (const auto& seat : bookedSeats) {
                    ImGui::Text("Seat %d: %s", seat.seatNumber, seat.passengerName.c_str());
                }
            }
        }

        ImGui::End();

        // Rendering
        ImGui::Render();
        int display_w, display_h;
        glfwGetFramebufferSize(window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        glClearColor(0.45f, 0.55f, 0.60f, 1.00f);
        glClear(GL_COLOR_BUFFER_BIT);

        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwSwapBuffers(window);
    }

    // Cleanup
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwDestroyWindow(window);
    glfwTerminate();
}
