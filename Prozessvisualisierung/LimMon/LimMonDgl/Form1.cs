using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;
using System.IO.Ports;

namespace LimMonDgl
{
    public partial class Form1 : Form
    {
        SerialPort _serPort;
        BinaryReaderEx _rd;
        BinaryWriterEx _wr;
        
        Int16 funkGen;


        Label[] _lblsvariables = new Label[3];

        public Form1()
        {
            InitializeComponent();

            _lblsvariables[0] = _lblA;
            _lblsvariables[1] = _lblB;
            _lblsvariables[2] = _lblLimitState;

            _cbToggleSend.Checked = false;
            _rbrRamp.Checked = true;
            funkGen = 1;
        }

        protected override void OnLoad(EventArgs e)
        {
            base.OnLoad(e);

            _serPort = new SerialPort("COM8", 500000, Parity.None, 8, StopBits.One);
            _serPort.Open();

            _rd = new BinaryReaderEx(_serPort.BaseStream);
            _wr = new BinaryWriterEx(_serPort.BaseStream);
            
            t1.Interval = 100; //100Hz
            t1.Enabled=true;
        }


        private void OnSendParameter(object sender, EventArgs e)
        {

            //Amplitude
            _wr.Write((byte)3);//Command 
            _wr.Write((float)Convert.ToDouble(_amplTxt.Text));

            //Frequenz
            _wr.Write((byte)2);//Command 
            _wr.Write((float)Convert.ToDouble(_frequTxt.Text));

            //Funktiongenerator
            _wr.Write((byte)4);//Command 
            _wr.Write((short)funkGen);

        }

        private void OnCurveFormChkChanged(object sender, EventArgs e)
        {
            if (_rbrRamp.Checked == true)
            {
                funkGen = 2;
            }
            if (_rbrRectangle.Checked == true)
            {
                funkGen = 1;
            }
        }

        private void OnActivate(object sender, EventArgs e)
        {
            if (_cbToggleSend.Checked == true)
            {
                _wr.Write((byte)1);//CMD =1
                _wr.Write((byte)1);//Daten =1
            }
            else
            {
                _wr.Write((byte)1);//CMD =1
                _wr.Write((byte)0);//Daten=0
            }
            _wr.Flush();
        }

        private void OnTimer(object sender, EventArgs e)
        {
            int id, knr, val;
            float valF;

            //Hier fragen wir mit 100Hz den Buffer ab
            while (_serPort.BytesToRead > 0)
            {
                //Laut Protokoll kommt zuerst eine ID
                id = _serPort.ReadByte();

                if (id == 10)
                { //Stringkanal

                    string Text = _rd.ReadCString();
                    //_msgList.Items.Add(Text);
                    //_msgList.SetSelected(_msgList.Items.Count - 1, true);
                }
                //Datentyp dekodieren
                if (id >= 11 && id <= 20)
                {
                    //Short(int16)
                    knr = id - 10;
                    val = _rd.ReadInt16();
                    _lblsvariables[knr - 1].Text = "Lim: "+val.ToString();

                    if (val.ToString() == "0")
                    {
                        _lblLimitState.Text = "Limit: Normal";
                    }
                    if (val.ToString() == "-1")
                    {
                        _lblLimitState.Text = "Limit: Lower";
                    }
                    if (val.ToString() == "1")
                    {
                        _lblLimitState.Text = "Limit: Upper";
                    }

                }

                if (id >= 21 && id <= 30)
                {
                    //Float
                    knr = id - 20;
                    valF = _rd.ReadSingle();
                    _lblsvariables[knr - 1].Text = "v1: "+valF.ToString();

                    
                }
            }
        }
    }
}
