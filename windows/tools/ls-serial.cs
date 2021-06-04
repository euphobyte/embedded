// FOR EDUCATIONAL PURPOSES ONLY, DO NOT USE IN PRODUCTION
// Source code is provided as-is without warranty, and disclaiming liability for damages resulting from using the source code.

using System.IO.Ports;

class LsSerial{
  static void Main(string[] args){
    System.Console.WriteLine("\r\nSerial Ports:");
    foreach (string s in SerialPort.GetPortNames())
      System.Console.WriteLine("  " + s);
  }
}
