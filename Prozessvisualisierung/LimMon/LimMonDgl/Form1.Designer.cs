namespace LimMonDgl
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
            this._lbldigFreq = new System.Windows.Forms.Label();
            this._lblAmplitude = new System.Windows.Forms.Label();
            this._rbrRamp = new System.Windows.Forms.RadioButton();
            this._rbrRectangle = new System.Windows.Forms.RadioButton();
            this._lblA = new System.Windows.Forms.Label();
            this._amplTxt = new System.Windows.Forms.TextBox();
            this._frequTxt = new System.Windows.Forms.TextBox();
            this._lblB = new System.Windows.Forms.Label();
            this._btnSendParameter = new System.Windows.Forms.Button();
            this._cbToggleSend = new System.Windows.Forms.CheckBox();
            this._lblLimitState = new System.Windows.Forms.Label();
            this.t1 = new System.Windows.Forms.Timer(this.components);
            this.SuspendLayout();
            // 
            // _lbldigFreq
            // 
            this._lbldigFreq.AutoSize = true;
            this._lbldigFreq.Location = new System.Drawing.Point(12, 35);
            this._lbldigFreq.Name = "_lbldigFreq";
            this._lbldigFreq.Size = new System.Drawing.Size(73, 13);
            this._lbldigFreq.TabIndex = 0;
            this._lbldigFreq.Text = "Dig. Frequenz";
            // 
            // _lblAmplitude
            // 
            this._lblAmplitude.AutoSize = true;
            this._lblAmplitude.Location = new System.Drawing.Point(12, 9);
            this._lblAmplitude.Name = "_lblAmplitude";
            this._lblAmplitude.Size = new System.Drawing.Size(53, 13);
            this._lblAmplitude.TabIndex = 1;
            this._lblAmplitude.Text = "Amplitude";
            // 
            // _rbrRamp
            // 
            this._rbrRamp.AutoSize = true;
            this._rbrRamp.Location = new System.Drawing.Point(13, 66);
            this._rbrRamp.Name = "_rbrRamp";
            this._rbrRamp.Size = new System.Drawing.Size(53, 17);
            this._rbrRamp.TabIndex = 2;
            this._rbrRamp.TabStop = true;
            this._rbrRamp.Text = "Ramp";
            this._rbrRamp.UseVisualStyleBackColor = true;
            this._rbrRamp.Click += new System.EventHandler(this.OnCurveFormChkChanged);
            // 
            // _rbrRectangle
            // 
            this._rbrRectangle.AutoSize = true;
            this._rbrRectangle.Location = new System.Drawing.Point(12, 89);
            this._rbrRectangle.Name = "_rbrRectangle";
            this._rbrRectangle.Size = new System.Drawing.Size(74, 17);
            this._rbrRectangle.TabIndex = 3;
            this._rbrRectangle.TabStop = true;
            this._rbrRectangle.Text = "Rectangle";
            this._rbrRectangle.UseVisualStyleBackColor = true;
            this._rbrRectangle.Click += new System.EventHandler(this.OnCurveFormChkChanged);
            // 
            // _lblA
            // 
            this._lblA.AutoSize = true;
            this._lblA.Location = new System.Drawing.Point(188, 13);
            this._lblA.Name = "_lblA";
            this._lblA.Size = new System.Drawing.Size(25, 13);
            this._lblA.TabIndex = 4;
            this._lblA.Text = "v1: ";
            // 
            // _amplTxt
            // 
            this._amplTxt.Location = new System.Drawing.Point(72, 9);
            this._amplTxt.Name = "_amplTxt";
            this._amplTxt.Size = new System.Drawing.Size(100, 20);
            this._amplTxt.TabIndex = 5;
            // 
            // _frequTxt
            // 
            this._frequTxt.Location = new System.Drawing.Point(91, 32);
            this._frequTxt.Name = "_frequTxt";
            this._frequTxt.Size = new System.Drawing.Size(81, 20);
            this._frequTxt.TabIndex = 6;
            // 
            // _lblB
            // 
            this._lblB.AutoSize = true;
            this._lblB.Location = new System.Drawing.Point(191, 35);
            this._lblB.Name = "_lblB";
            this._lblB.Size = new System.Drawing.Size(26, 13);
            this._lblB.TabIndex = 7;
            this._lblB.Text = "Lim:";
            // 
            // _btnSendParameter
            // 
            this._btnSendParameter.Location = new System.Drawing.Point(107, 66);
            this._btnSendParameter.Name = "_btnSendParameter";
            this._btnSendParameter.Size = new System.Drawing.Size(142, 23);
            this._btnSendParameter.TabIndex = 8;
            this._btnSendParameter.Text = "Send Parameter";
            this._btnSendParameter.UseVisualStyleBackColor = true;
            this._btnSendParameter.Click += new System.EventHandler(this.OnSendParameter);
            // 
            // _cbToggleSend
            // 
            this._cbToggleSend.AutoSize = true;
            this._cbToggleSend.Location = new System.Drawing.Point(12, 125);
            this._cbToggleSend.Name = "_cbToggleSend";
            this._cbToggleSend.Size = new System.Drawing.Size(98, 17);
            this._cbToggleSend.TabIndex = 9;
            this._cbToggleSend.Text = "Uc send on/off";
            this._cbToggleSend.UseVisualStyleBackColor = true;
            this._cbToggleSend.Click += new System.EventHandler(this.OnActivate);
            // 
            // _lblLimitState
            // 
            this._lblLimitState.AutoSize = true;
            this._lblLimitState.Location = new System.Drawing.Point(144, 125);
            this._lblLimitState.Name = "_lblLimitState";
            this._lblLimitState.Size = new System.Drawing.Size(59, 13);
            this._lblLimitState.TabIndex = 10;
            this._lblLimitState.Text = "LimitState: ";
            // 
            // t1
            // 
            this.t1.Tick += new System.EventHandler(this.OnTimer);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(288, 159);
            this.Controls.Add(this._lblLimitState);
            this.Controls.Add(this._cbToggleSend);
            this.Controls.Add(this._btnSendParameter);
            this.Controls.Add(this._lblB);
            this.Controls.Add(this._frequTxt);
            this.Controls.Add(this._amplTxt);
            this.Controls.Add(this._lblA);
            this.Controls.Add(this._rbrRectangle);
            this.Controls.Add(this._rbrRamp);
            this.Controls.Add(this._lblAmplitude);
            this.Controls.Add(this._lbldigFreq);
            this.Name = "Form1";
            this.Text = "Form1";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label _lbldigFreq;
        private System.Windows.Forms.Label _lblAmplitude;
        private System.Windows.Forms.RadioButton _rbrRamp;
        private System.Windows.Forms.RadioButton _rbrRectangle;
        private System.Windows.Forms.Label _lblA;
        private System.Windows.Forms.TextBox _amplTxt;
        private System.Windows.Forms.TextBox _frequTxt;
        private System.Windows.Forms.Label _lblB;
        private System.Windows.Forms.Button _btnSendParameter;
        private System.Windows.Forms.CheckBox _cbToggleSend;
        private System.Windows.Forms.Label _lblLimitState;
        private System.Windows.Forms.Timer t1;
    }
}

