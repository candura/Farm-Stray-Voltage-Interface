using namespace System;
using namespace System::Data;
using namespace System::IO;
ref class Settings {
public:
	Settings (String^);
	UInt16 numRecord, numChannel, c2p, c2s, c2pN, c2sN,iDecScale, iBinScale, iNDecScale, iNBinScale, vNBinScale,vNDecScale, interval, seconds;
	Int16 iCal1, iCal2, iCal3, iCal4, vCal4;
	DateTime start; DateTime end;
	bool rightLogger;
};
Settings::Settings (String^ file)
		{
			//Initializing the reader that will read the binary file, and the byte array to hold the header
			BinaryReader^ binReader = gcnew BinaryReader( File::Open( file, FileMode::Open));
			array<Byte>^ header = gcnew array<Byte>(256);

			//Reading from file into the header
			for (int n =0; n<256; n++)
				header[n] = binReader->ReadByte();
			binReader->Close();

			if (System::Convert::ToChar (header[10]) == '2' && System::Convert::ToChar (header[11]) == '1' && System::Convert::ToChar (header[12]) == '3'&& System::Convert::ToChar (header[13]) == 'T')
			{
			rightLogger = true;
			//Setting the values based on their respective positions in the file
			numRecord = System::BitConverter::ToUInt16 (gcnew array<Byte>{header[36],header[35]},0);//Number of records
			c2p = System::BitConverter::ToUInt16 (gcnew array<Byte>{header[45],header[44]},0);//CT Primary
			c2s = System::BitConverter::ToUInt16 (gcnew array<Byte>{header[47],header[46]},0);//CT Secondary
			c2pN = System::BitConverter::ToUInt16 (gcnew array<Byte>{header[49],header[48]},0);//CT Primary
			c2sN = System::BitConverter::ToUInt16 (gcnew array<Byte>{header[51],header[50]},0);//CT Secondary
			vNDecScale = System::BitConverter::ToUInt16 (gcnew array<Byte>{header[57],header[56]},0); //Voltage decimal scale
			vNBinScale = System::BitConverter::ToUInt16 (gcnew array<Byte>{header[59],header[58]},0); //Voltage binary scale
			iDecScale = System::BitConverter::ToUInt16 (gcnew array<Byte>{header[77],header[76]},0);//Current decimal scale
			iBinScale = System::BitConverter::ToUInt16 (gcnew array<Byte>{header[79],header[78]},0);//Current binary scale
			iNDecScale = System::BitConverter::ToUInt16 (gcnew array<Byte>{header[81],header[80]},0);//Neutral current decimal scale
			iNBinScale = System::BitConverter::ToUInt16 (gcnew array<Byte>{header[83],header[82]},0);//Neutral current binary scale
			vCal4 = System::BitConverter::ToInt16 (gcnew array<Byte>{header[67],header[66]},0); //Channel 4 Voltage calibration
			iCal1 = System::BitConverter::ToInt16 (gcnew array<Byte>{header[85],header[84]},0);//Channel 1 current calibration
			iCal2 = System::BitConverter::ToInt16 (gcnew array<Byte>{header[87],header[86]},0);//Channel 2 current calibration
			iCal3 = System::BitConverter::ToInt16 (gcnew array<Byte>{header[89],header[88]},0);//Channel 3 current calibration
			iCal4 = System::BitConverter::ToInt16 (gcnew array<Byte>{header[91],header[90]},0);//Neutral current calibration
			interval = System::BitConverter::ToUInt16(gcnew array<Byte>{header[112],0},0); 

			if (interval % 64 >= 32)
				interval = interval * 60;

			//Reading in the logger start time and last record time
			start = DateTime(System::BitConverter::ToInt16 (gcnew array<Byte>{header[115],header[114]},0),System::BitConverter::ToInt16 (gcnew array<Byte>{header[116],0x00},0),System::BitConverter::ToInt16 (gcnew array<Byte>{header[117],0x00},0),System::BitConverter::ToInt16 (gcnew array<Byte>{header[118],0x00},0),System::BitConverter::ToInt16 (gcnew array<Byte>{header[119],0x00},0),System::BitConverter::ToInt16 (gcnew array<Byte>{header[120],0x00},0));
			end = DateTime(System::BitConverter::ToInt16 (gcnew array<Byte>{header[122],header[121]},0),System::BitConverter::ToInt16 (gcnew array<Byte>{header[123],0x00},0),System::BitConverter::ToInt16 (gcnew array<Byte>{header[124],0x00},0),System::BitConverter::ToInt16 (gcnew array<Byte>{header[125],0x00},0),System::BitConverter::ToInt16 (gcnew array<Byte>{header[126],0x00},0),System::BitConverter::ToInt16 (gcnew array<Byte>{header[127],0x00},0));
			}
			else
				rightLogger = false;
			binReader->Close();
		}
