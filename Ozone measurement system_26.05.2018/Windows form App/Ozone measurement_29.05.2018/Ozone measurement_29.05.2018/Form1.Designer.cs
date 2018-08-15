namespace Ozone_measurement_29._05._2018
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.COMStart_button = new System.Windows.Forms.Button();
            this.COMPorts_comboBox = new System.Windows.Forms.ComboBox();
            this.COMStop_button = new System.Windows.Forms.Button();
            this.COMRefresh_button = new System.Windows.Forms.Button();
            this.SerialPort = new System.IO.Ports.SerialPort(this.components);
            this.COMPort_panel = new System.Windows.Forms.Panel();
            this.COMPanelName_label = new System.Windows.Forms.Label();
            this.menuStrip1 = new System.Windows.Forms.MenuStrip();
            this.COMPort_StripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.PWMSetting_ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.PWMSetting_panel = new System.Windows.Forms.Panel();
            this.PWMSendSetting_button = new System.Windows.Forms.Button();
            this.CAMGetPicture_checkBox = new System.Windows.Forms.CheckBox();
            this.PWMGataGet_checkBox = new System.Windows.Forms.CheckBox();
            this.PWMDuration_trackBar = new System.Windows.Forms.TrackBar();
            this.PWMDuration_label = new System.Windows.Forms.Label();
            this.PWMIntensity_label = new System.Windows.Forms.Label();
            this.PWMIntensity_trackBar = new System.Windows.Forms.TrackBar();
            this.PWMGraph_pictureBox = new System.Windows.Forms.PictureBox();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.COMPort_panel.SuspendLayout();
            this.menuStrip1.SuspendLayout();
            this.PWMSetting_panel.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.PWMDuration_trackBar)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.PWMIntensity_trackBar)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.PWMGraph_pictureBox)).BeginInit();
            this.SuspendLayout();
            // 
            // COMStart_button
            // 
            this.COMStart_button.Location = new System.Drawing.Point(15, 79);
            this.COMStart_button.Name = "COMStart_button";
            this.COMStart_button.Size = new System.Drawing.Size(103, 27);
            this.COMStart_button.TabIndex = 0;
            this.COMStart_button.Text = "Открыть";
            this.COMStart_button.UseVisualStyleBackColor = true;
            this.COMStart_button.Click += new System.EventHandler(this.COMStart_button_Click);
            // 
            // COMPorts_comboBox
            // 
            this.COMPorts_comboBox.FormattingEnabled = true;
            this.COMPorts_comboBox.Location = new System.Drawing.Point(15, 37);
            this.COMPorts_comboBox.Name = "COMPorts_comboBox";
            this.COMPorts_comboBox.Size = new System.Drawing.Size(131, 21);
            this.COMPorts_comboBox.TabIndex = 1;
            // 
            // COMStop_button
            // 
            this.COMStop_button.Location = new System.Drawing.Point(126, 79);
            this.COMStop_button.Name = "COMStop_button";
            this.COMStop_button.Size = new System.Drawing.Size(103, 27);
            this.COMStop_button.TabIndex = 2;
            this.COMStop_button.Text = "Закрыть";
            this.COMStop_button.UseVisualStyleBackColor = true;
            this.COMStop_button.Click += new System.EventHandler(this.COMStop_button_Click);
            // 
            // COMRefresh_button
            // 
            this.COMRefresh_button.Location = new System.Drawing.Point(165, 37);
            this.COMRefresh_button.Name = "COMRefresh_button";
            this.COMRefresh_button.Size = new System.Drawing.Size(64, 27);
            this.COMRefresh_button.TabIndex = 3;
            this.COMRefresh_button.Text = "Обновить";
            this.COMRefresh_button.UseVisualStyleBackColor = true;
            this.COMRefresh_button.Click += new System.EventHandler(this.COMRefresh_button_Click);
            // 
            // SerialPort
            // 
            this.SerialPort.BaudRate = 1200;
            // 
            // COMPort_panel
            // 
            this.COMPort_panel.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.COMPort_panel.Controls.Add(this.COMPanelName_label);
            this.COMPort_panel.Controls.Add(this.COMPorts_comboBox);
            this.COMPort_panel.Controls.Add(this.COMRefresh_button);
            this.COMPort_panel.Controls.Add(this.COMStart_button);
            this.COMPort_panel.Controls.Add(this.COMStop_button);
            this.COMPort_panel.Location = new System.Drawing.Point(12, 32);
            this.COMPort_panel.Name = "COMPort_panel";
            this.COMPort_panel.Size = new System.Drawing.Size(279, 131);
            this.COMPort_panel.TabIndex = 4;
            this.COMPort_panel.Visible = false;
            // 
            // COMPanelName_label
            // 
            this.COMPanelName_label.AutoSize = true;
            this.COMPanelName_label.Location = new System.Drawing.Point(12, 10);
            this.COMPanelName_label.Name = "COMPanelName_label";
            this.COMPanelName_label.Size = new System.Drawing.Size(57, 13);
            this.COMPanelName_label.TabIndex = 5;
            this.COMPanelName_label.Text = "COM порт";
            // 
            // menuStrip1
            // 
            this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.COMPort_StripMenuItem,
            this.PWMSetting_ToolStripMenuItem});
            this.menuStrip1.Location = new System.Drawing.Point(0, 0);
            this.menuStrip1.Name = "menuStrip1";
            this.menuStrip1.Size = new System.Drawing.Size(1117, 24);
            this.menuStrip1.TabIndex = 5;
            this.menuStrip1.Text = "menuStrip1";
            // 
            // COMPort_StripMenuItem
            // 
            this.COMPort_StripMenuItem.Name = "COMPort_StripMenuItem";
            this.COMPort_StripMenuItem.Size = new System.Drawing.Size(76, 20);
            this.COMPort_StripMenuItem.Text = "COM порт";
            this.COMPort_StripMenuItem.Click += new System.EventHandler(this.COMPort_StripMenuItem_Click);
            // 
            // PWMSetting_ToolStripMenuItem
            // 
            this.PWMSetting_ToolStripMenuItem.Name = "PWMSetting_ToolStripMenuItem";
            this.PWMSetting_ToolStripMenuItem.Size = new System.Drawing.Size(137, 20);
            this.PWMSetting_ToolStripMenuItem.Text = "Настройка установки";
            this.PWMSetting_ToolStripMenuItem.Click += new System.EventHandler(this.PWMSetting_ToolStripMenuItem_Click);
            // 
            // PWMSetting_panel
            // 
            this.PWMSetting_panel.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.PWMSetting_panel.Controls.Add(this.PWMSendSetting_button);
            this.PWMSetting_panel.Controls.Add(this.CAMGetPicture_checkBox);
            this.PWMSetting_panel.Controls.Add(this.PWMGataGet_checkBox);
            this.PWMSetting_panel.Controls.Add(this.PWMDuration_trackBar);
            this.PWMSetting_panel.Controls.Add(this.PWMDuration_label);
            this.PWMSetting_panel.Controls.Add(this.PWMIntensity_label);
            this.PWMSetting_panel.Controls.Add(this.PWMIntensity_trackBar);
            this.PWMSetting_panel.Location = new System.Drawing.Point(320, 32);
            this.PWMSetting_panel.Name = "PWMSetting_panel";
            this.PWMSetting_panel.Size = new System.Drawing.Size(581, 208);
            this.PWMSetting_panel.TabIndex = 6;
            this.PWMSetting_panel.Visible = false;
            // 
            // PWMSendSetting_button
            // 
            this.PWMSendSetting_button.Location = new System.Drawing.Point(378, 153);
            this.PWMSendSetting_button.Name = "PWMSendSetting_button";
            this.PWMSendSetting_button.Size = new System.Drawing.Size(153, 41);
            this.PWMSendSetting_button.TabIndex = 7;
            this.PWMSendSetting_button.Text = "Передать данные на установку";
            this.PWMSendSetting_button.UseVisualStyleBackColor = true;
            this.PWMSendSetting_button.Click += new System.EventHandler(this.PWMSendSetting_button_Click);
            // 
            // CAMGetPicture_checkBox
            // 
            this.CAMGetPicture_checkBox.AutoSize = true;
            this.CAMGetPicture_checkBox.Location = new System.Drawing.Point(147, 166);
            this.CAMGetPicture_checkBox.Name = "CAMGetPicture_checkBox";
            this.CAMGetPicture_checkBox.Size = new System.Drawing.Size(148, 17);
            this.CAMGetPicture_checkBox.TabIndex = 6;
            this.CAMGetPicture_checkBox.Text = "Изображение с камеры";
            this.CAMGetPicture_checkBox.UseVisualStyleBackColor = true;
            // 
            // PWMGataGet_checkBox
            // 
            this.PWMGataGet_checkBox.AutoSize = true;
            this.PWMGataGet_checkBox.Location = new System.Drawing.Point(21, 166);
            this.PWMGataGet_checkBox.Name = "PWMGataGet_checkBox";
            this.PWMGataGet_checkBox.Size = new System.Drawing.Size(120, 17);
            this.PWMGataGet_checkBox.TabIndex = 5;
            this.PWMGataGet_checkBox.Text = "Получение данных";
            this.PWMGataGet_checkBox.UseVisualStyleBackColor = true;
            // 
            // PWMDuration_trackBar
            // 
            this.PWMDuration_trackBar.Location = new System.Drawing.Point(21, 103);
            this.PWMDuration_trackBar.Maximum = 99;
            this.PWMDuration_trackBar.Name = "PWMDuration_trackBar";
            this.PWMDuration_trackBar.Size = new System.Drawing.Size(522, 45);
            this.PWMDuration_trackBar.TabIndex = 3;
            this.PWMDuration_trackBar.TickStyle = System.Windows.Forms.TickStyle.Both;
            this.PWMDuration_trackBar.Scroll += new System.EventHandler(this.PWMDuration_trackBar_Scroll);
            // 
            // PWMDuration_label
            // 
            this.PWMDuration_label.AutoSize = true;
            this.PWMDuration_label.Location = new System.Drawing.Point(42, 87);
            this.PWMDuration_label.Name = "PWMDuration_label";
            this.PWMDuration_label.Size = new System.Drawing.Size(83, 13);
            this.PWMDuration_label.TabIndex = 2;
            this.PWMDuration_label.Text = "Длительность:";
            // 
            // PWMIntensity_label
            // 
            this.PWMIntensity_label.AutoSize = true;
            this.PWMIntensity_label.Location = new System.Drawing.Point(37, 10);
            this.PWMIntensity_label.Name = "PWMIntensity_label";
            this.PWMIntensity_label.Size = new System.Drawing.Size(88, 13);
            this.PWMIntensity_label.TabIndex = 1;
            this.PWMIntensity_label.Text = "Интенсивность:";
            // 
            // PWMIntensity_trackBar
            // 
            this.PWMIntensity_trackBar.Location = new System.Drawing.Point(21, 29);
            this.PWMIntensity_trackBar.Maximum = 100;
            this.PWMIntensity_trackBar.Name = "PWMIntensity_trackBar";
            this.PWMIntensity_trackBar.Size = new System.Drawing.Size(522, 45);
            this.PWMIntensity_trackBar.TabIndex = 0;
            this.PWMIntensity_trackBar.TickStyle = System.Windows.Forms.TickStyle.Both;
            this.PWMIntensity_trackBar.Scroll += new System.EventHandler(this.PWMIntensity_trackBar_Scroll);
            // 
            // PWMGraph_pictureBox
            // 
            this.PWMGraph_pictureBox.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.PWMGraph_pictureBox.BackColor = System.Drawing.SystemColors.Window;
            this.PWMGraph_pictureBox.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.PWMGraph_pictureBox.Location = new System.Drawing.Point(520, 66);
            this.PWMGraph_pictureBox.Name = "PWMGraph_pictureBox";
            this.PWMGraph_pictureBox.Size = new System.Drawing.Size(585, 453);
            this.PWMGraph_pictureBox.TabIndex = 7;
            this.PWMGraph_pictureBox.TabStop = false;
            this.PWMGraph_pictureBox.Paint += new System.Windows.Forms.PaintEventHandler(this.PWMGraph_pictureBox_Paint);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(503, 78);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(15, 13);
            this.label1.TabIndex = 8;
            this.label1.Text = "N";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(1040, 523);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(34, 13);
            this.label2.TabIndex = 9;
            this.label2.Text = "t, сек";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1117, 545);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.PWMGraph_pictureBox);
            this.Controls.Add(this.PWMSetting_panel);
            this.Controls.Add(this.COMPort_panel);
            this.Controls.Add(this.menuStrip1);
            this.MainMenuStrip = this.menuStrip1;
            this.Name = "Form1";
            this.Text = "Form1";
            this.COMPort_panel.ResumeLayout(false);
            this.COMPort_panel.PerformLayout();
            this.menuStrip1.ResumeLayout(false);
            this.menuStrip1.PerformLayout();
            this.PWMSetting_panel.ResumeLayout(false);
            this.PWMSetting_panel.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.PWMDuration_trackBar)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.PWMIntensity_trackBar)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.PWMGraph_pictureBox)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button COMStart_button;
        private System.Windows.Forms.ComboBox COMPorts_comboBox;
        private System.Windows.Forms.Button COMStop_button;
        private System.Windows.Forms.Button COMRefresh_button;
        private System.IO.Ports.SerialPort SerialPort;
        private System.Windows.Forms.Panel COMPort_panel;
        private System.Windows.Forms.Label COMPanelName_label;
        private System.Windows.Forms.MenuStrip menuStrip1;
        private System.Windows.Forms.ToolStripMenuItem COMPort_StripMenuItem;
        private System.Windows.Forms.Panel PWMSetting_panel;
        private System.Windows.Forms.TrackBar PWMIntensity_trackBar;
        private System.Windows.Forms.Label PWMIntensity_label;
        private System.Windows.Forms.TrackBar PWMDuration_trackBar;
        private System.Windows.Forms.Label PWMDuration_label;
        private System.Windows.Forms.ToolStripMenuItem PWMSetting_ToolStripMenuItem;
        private System.Windows.Forms.CheckBox CAMGetPicture_checkBox;
        private System.Windows.Forms.CheckBox PWMGataGet_checkBox;
        private System.Windows.Forms.Button PWMSendSetting_button;
        private System.Windows.Forms.PictureBox PWMGraph_pictureBox;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
    }
}

