// In order to test the UART functionality of the ARM processor we use some tools in Windows 10, written in C#
// © Simon Stok, June 2021

using System;
using System.Management;
using System.Collections.Generic;
using System.Linq;
using System.IO.Ports;

class LsSerial{
  static void Main(string[] args){
    System.Console.WriteLine("\r\nSerial Ports:");
    foreach (string s in SerialPort.GetPortNames())
      System.Console.WriteLine("  " + s);
  }
}
