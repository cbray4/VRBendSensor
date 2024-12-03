using Godot;
using System;
using System.IO.Ports;

public partial class serialtesting : Label
{
	SerialPort _serialPort = new SerialPort("COM1", 9600, Parity.None, 8, StopBits.One);

	// Called when the node enters the scene tree for the first time.
	public override void _Ready()
	{
		/*
			First, create serialport object
			then you gotta set a few variables:
			* Port Name
			* Baud Rate
			* Parity
			* DataBits
			* Stop Bits
			* Handshake
			
			I don't know what these mean. Figure it out.
			
			You also need Read and Write timeouts. They should be pretty long.
			
			Then you can open the serial port and start doing stuff.
		*/
		_serialPort.Handshake = Handshake.None;
		_serialPort.WriteTimeout = 500;
		_serialPort.DataReceived += new SerialDataReceivedEventHandler(sp_DataReceived);
		_serialPort.Open();
	}

	// Called every frame. 'delta' is the elapsed time since the previous frame.
	public override void _Process(double delta)
	{
	}

	void sp_DataReceived(object sender, SerialDataReceivedEventArgs e)
	{
		string text = _serialPort.ReadLine();
		self.text = text;
	}

}
