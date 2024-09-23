### Space Mission Planner (C++)

**Overview:**
This project is a (WIP) C++ program designed to help plan space missions. Users can input mission parameters like the
target planet, payload weight, and fuel budget. The program then calculates optimal trajectories, launch windows, and
fuel requirements.

**Key Features:**

- Input mission objectives (target planet, payload weight, fuel budget).
- Calculate and display mission trajectories, launch windows, and fuel requirements.
- Expansion features include real-world constraints like launch windows and propulsion system efficiency.

**How to Run:**

1. **Clone the repository:**
   ```sh
   git clone https://github.com/T-Lind/space-mission-planner.git
   cd space_mission_planner
   ```

2. **Build the project using CMake:**
   ```sh
   mkdir build
   cd build
   cmake ..
   make
   ```

3. **Run the executable:**
   ```sh
   ./space_mission_planner
   ```

4. **Follow the on-screen prompts to input mission parameters.**