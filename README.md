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
├── CMakeLists.txt # Build configuration
├── main.cpp # CLI application entry point
├── gui_main.cpp # GUI application entry point
├── reservation_system.cpp # Core reservation logic implementation
├── reservation_system.hpp # Reservation system header
├── gui.cpp # GUI implementation (Dear ImGui)
├── gui.hpp # GUI declarations
├── imgui/ # Dear ImGui source and backends
├── test/
│ └── test_reservation_system.cpp # Google Test unit tests

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

```bash
mkdir build
cd build
cmake ..
make

---

## Running the Application from Linux Terminal

- **Run the CLI app :** "./ticket_cli"
- **Run the GUI app :** "./ticket_gui" 

---

## Running Unit Tests

- **Run unit tests executable :** "./unit_tests"