# Ticket Reservation System

A comprehensive ticket reservation system implemented in modern C++17, featuring both a **command-line interface (CLI)** and a **graphical user interface (GUI)** built with **Dear ImGui**. The project includes robust unit tests using **Google Test**.

---

## Table of Contents

- [Overview](#overview)  
- [Features](#features)  
- [Project Structure](#project-structure)  
- [Prerequisites](#prerequisites)  
- [Building the Project](#building-the-project)  
- [Running the Applications](#running-the-applications)  
- [Running Unit Tests](#running-unit-tests)  
- [Technologies Used](#technologies-used)  
- [Future Improvements](#future-improvements)  

---

## Overview

This project simulates a ticket reservation system where users can book, cancel, and view seats. It demonstrates clean separation of concerns with core business logic encapsulated in a reusable `ReservationSystem` class. The UI is provided both as a terminal-based menu and a modern GUI using Dear ImGui with GLFW and OpenGL backend.

---

## Features

- **CLI Mode:** Menu-driven terminal interface to manage bookings.
- **GUI Mode:** Interactive GUI with seat display, booking, cancellation, and summary.
- **Unit Tests:** Thorough tests covering core functionality using Google Test.
- **Modular Codebase:** Clear separation between logic, UI, and tests.
- **Cross-platform Compatible:** Designed to build and run on Linux and Windows.

---

## Project Structure

TicketReserve/
├── CMakeLists.txt
├── README.md
├── gui.cpp
├── gui.hpp
├── gui_main.cpp
├── imgui
│   ├── backends
│   │   ├── imgui_impl_glfw.cpp
│   │   ├── imgui_impl_glfw.h
│   │   ├── imgui_impl_opengl3.cpp
│   │   ├── imgui_impl_opengl3.h
│   │   └── imgui_impl_opengl3_loader.h
│   ├── imconfig.h
│   ├── imgui.cpp
│   ├── imgui.h
│   ├── imgui_demo.cpp
│   ├── imgui_draw.cpp
│   ├── imgui_internal.h
│   ├── imgui_tables.cpp
│   ├── imgui_widgets.cpp
│   ├── imstb_rectpack.h
│   ├── imstb_textedit.h
│   └── imstb_truetype.h
├── main.cpp
├── reservation_system.cpp
├── reservation_system.hpp
├── structure.txt
└── test
    ├── CMakeLists.txt
    └── test_reserve_system.cpp

---

## Prerequisites

- **C++17 compatible compiler** (`g++` recommended)
- **CMake >= 3.10**
- **Google Test** (installed or vendored)
- **GLFW** library (for GUI)
- **OpenGL** development headers
- For Windows: MinGW or Visual Studio with GLFW binaries installed

---

## Building the Project


- mkdir build
- cd build
- cmake ..
- make

---

## Running the Application from Linux Terminal

- Run the CLI app : ./ticket_cli
- Run the GUI app : ./ticket_gui 

---

## Running Unit Tests

- Run unit tests executable : ./unit_tests
