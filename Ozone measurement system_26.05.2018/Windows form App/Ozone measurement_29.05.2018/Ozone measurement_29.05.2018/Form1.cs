using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO.Ports;


namespace Ozone_measurement_29._05._2018
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            COM_ListRefresh();

           
        }
        /*         Работаем с COM портами
         * 
         * 
         * 
         * 
         *
         */
        private void COM_ListRefresh()
        {
            COMPorts_comboBox.Items.Clear();
            foreach(string portName in SerialPort.GetPortNames())
            {
                COMPorts_comboBox.Items.Add(portName);
            }
            COMPorts_comboBox.SelectionLength = 0;
            COMPorts_comboBox.SelectedIndex = 0;
            // COMPorts_comboBox.SelectedIndex = ;
        }

        private void COMRefresh_button_Click(object sender, EventArgs e)
        {
            COM_ListRefresh();
        }

        private void COMStart_button_Click(object sender, EventArgs e)
        {
            if (!SerialPort.IsOpen)
            {
                try
                {
                    SerialPort.PortName = ((string)COMPorts_comboBox.SelectedItem);
                    COMStart_button.Text = "Подключение";
                    SerialPort.Open();
                    COMStart_button.Text = "Подключен";
                    COMStop_button.Text = "Закрыть";
                }
                catch (Exception ex)
                {
                    MessageBox.Show(ex.Message.ToString());
                }
            }
            else
            {
                MessageBox.Show("Хей, твой порт уже открыт.");
            }
        }

        private void COMStop_button_Click(object sender, EventArgs e)
        {
            try
            {                
                COMStop_button.Text = "Отключение";
                SerialPort.Close();
                COMStop_button.Text = "Отключен";
                COMStart_button.Text = "Открыть";
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message.ToString());
            }
        }


        /*         Работаем с Меню
         * 
         * 
         * 
         * 
         *
         */
        private void COMPort_StripMenuItem_Click(object sender, EventArgs e)
        {
            if (!COMPort_panel.Visible)
            {
                COMPort_panel.Visible = true;
                COMPort_panel.BringToFront();
                label1.BringToFront();
            }
            else
            {
                COMPort_panel.Visible = false;
            }
        }


        private void PWMSetting_ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if(!PWMSetting_panel.Visible)
            {
                PWMSetting_panel.Visible = true;
                PWMSetting_panel.BringToFront();
            }
            else
            {
                PWMSetting_panel.Visible = false;
            }
        }
        
        private void PWMIntensity_trackBar_Scroll(object sender, EventArgs e)
        {
            PWMIntensity_label.Text = String.Format("Интенсивность: {0} %", PWMIntensity_trackBar.Value);
        }

        private void PWMDuration_trackBar_Scroll(object sender, EventArgs e)
        {
            PWMDuration_label.Text = String.Format("Длительность: {0} минут", PWMDuration_trackBar.Value);
        }

        private void PWMSendSetting_button_Click(object sender, EventArgs e)
        {
            //   SerialPort.
            SerialPort.WriteLine("001000");
            System.Threading.Thread.Sleep(550);

            while (SerialPort.ReadChar() !=  '0') ;

            SerialPort.WriteLine("011000");
            System.Threading.Thread.Sleep(550);


            while (SerialPort.ReadChar() != '0') ;

            SerialPort.WriteLine("110010");
            System.Threading.Thread.Sleep(550);    
            
        }

        /*         Работаем с Полученными данными
        * 
        * 
        * 
        * 
        *
        */
        private void PWMGraphCreate_pictureBox(int X, int Y)
        {
            try
            {
                // Задаем размер нашей формы
                this.Height = 700;
                this.Width = 900;

                // Задаем положение pictureBox1, координаты левого верхнего угла относительно формы
                this.PWMGraph_pictureBox.Location = new System.Drawing.Point(40, 40);

                // Задаем размер pictureBox1
                this.PWMGraph_pictureBox.Width = 600;
                this.PWMGraph_pictureBox.Height = 500;

               // this.PWMGraph_pictureBox.Location = new System.Drawing.Point(40, 40);
               // Graphics PWMGraph = PWMGraph_pictureBox.CreateGraphics();
                int XLenght = PWMGraph_pictureBox.Size.Width;
                int YLenght = PWMGraph_pictureBox.Size.Height;
                
               PointF[] ptf = new PointF[XLenght];

                //  PWMGraph.Clear(PWMGraph_pictureBox.BackColor);

                for (int i = 0; i < XLenght; i++)
                {
                    ptf[i].X = i;
                    ptf[i].Y = (float)((YLenght / 2) * (1 - Math.Sin(i * 3 * Math.PI / (XLenght - 1))));
                }

                //    PWMGraph.DrawLine(Pens.Red, 0,0 , XLenght,YLenght );
                PWMGraph_pictureBox.BackColor = Color.White;
                PWMGraph_pictureBox.Visible = true;
                PWMGraph_pictureBox.Paint += new System.Windows.Forms.PaintEventHandler(this.PWMGraph_pictureBox_Paint);
                //    PWMGraph.Dispose();
                //    PWMGraph_pictureBox.Invalidate();
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message.ToString());
            }
        }

       

        private void Forml_Paint(object sender, PaintEventArgs e)
        {
           
        }

        private void PWMGraph_pictureBox_Paint(object sender, PaintEventArgs e)
        {
            Graphics PWMGraph = e.Graphics;
            int XLenght = PWMGraph_pictureBox.Size.Width;
            int YLenght = PWMGraph_pictureBox.Size.Height;

            PointF[] ptf = new PointF[XLenght];

            //  PWMGraph.Clear(PWMGraph_pictureBox.BackColor);

            for (int i = 0; i < XLenght; i++)
            {
                ptf[i].X = i;
                ptf[i].Y = (float)((YLenght / 2) * (1 - Math.Sin(i * 10 * Math.PI / (XLenght - 1))));
            }
            PWMGraph.DrawLines(Pens.Red, ptf);
           // PWMGraph.DrawLine(Pens.Red, 0, 0, PWMGraph_pictureBox.Size.Width, PWMGraph_pictureBox.Size.Height);
        }
    }
}
