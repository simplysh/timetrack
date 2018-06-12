#include "io.h"
#include "time.h"
#include <fstream>
#include <string>
#include <iostream>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <cstdlib>

Time getTime(std::string file) {
  Time zero;
  std::ifstream in(file);

  if (in.is_open()) {
    std::string line;
    std::string last;

    while (std::getline(in, line)) {
      last = line;
    }

    in.close();

    if (last.empty()) {
      std::cout << "No entry found, using " << zero << std::endl;
      
      return zero;
    } else {
      return Time(last.substr(0, last.find(',')));
    }
  }

  std::cout << "Can't open '" << file << "' for reading." << std::endl;
  std::exit(1);

  return zero;
}

bool putTime(std::string file, Time time) {
  std::ofstream out;

  auto now = std::time(nullptr);
  auto tm = *std::localtime(&now);

  std::ostringstream oss;
  oss << std::put_time(&tm, "%Y-%m-%dT%H:%M:%S");
  std::string pretty = oss.str();

  out.open(file, std::ios::out | std::ios::app);
  
  if (out.is_open()) {
    out << time << "," << pretty << std::endl;
    out.close();

    return true;
  }

  return false;
}