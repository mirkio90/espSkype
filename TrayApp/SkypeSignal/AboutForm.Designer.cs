namespace SkypeSignal
{
    partial class AboutForm
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
            this.LogoPanel = new System.Windows.Forms.Panel();
            this.btn_Close = new System.Windows.Forms.Button();
            this.lbl_ProductName = new System.Windows.Forms.Label();
            this.lbl_Version = new System.Windows.Forms.Label();
            this.lbl_Copyright = new System.Windows.Forms.Label();
            this.tb_Description = new System.Windows.Forms.TextBox();
            this.SuspendLayout();
            // 
            // LogoPanel
            // 
            this.LogoPanel.Location = new System.Drawing.Point(4, 6);
            this.LogoPanel.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.LogoPanel.Name = "LogoPanel";
            this.LogoPanel.Size = new System.Drawing.Size(315, 483);
            this.LogoPanel.TabIndex = 0;
            // 
            // btn_Close
            // 
            this.btn_Close.Location = new System.Drawing.Point(639, 409);
            this.btn_Close.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.btn_Close.Name = "btn_Close";
            this.btn_Close.Size = new System.Drawing.Size(110, 42);
            this.btn_Close.TabIndex = 1;
            this.btn_Close.Text = "Close";
            this.btn_Close.UseVisualStyleBackColor = true;
            this.btn_Close.Click += new System.EventHandler(this.btn_Close_Click);
            // 
            // lbl_ProductName
            // 
            this.lbl_ProductName.AutoSize = true;
            this.lbl_ProductName.Location = new System.Drawing.Point(334, 14);
            this.lbl_ProductName.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.lbl_ProductName.Name = "lbl_ProductName";
            this.lbl_ProductName.Size = new System.Drawing.Size(120, 20);
            this.lbl_ProductName.TabIndex = 3;
            this.lbl_ProductName.Text = "{Product Name}";
            // 
            // lbl_Version
            // 
            this.lbl_Version.AutoSize = true;
            this.lbl_Version.Location = new System.Drawing.Point(334, 48);
            this.lbl_Version.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.lbl_Version.Name = "lbl_Version";
            this.lbl_Version.Size = new System.Drawing.Size(73, 20);
            this.lbl_Version.TabIndex = 4;
            this.lbl_Version.Text = "{Version}";
            // 
            // lbl_Copyright
            // 
            this.lbl_Copyright.AutoSize = true;
            this.lbl_Copyright.Location = new System.Drawing.Point(334, 83);
            this.lbl_Copyright.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.lbl_Copyright.Name = "lbl_Copyright";
            this.lbl_Copyright.Size = new System.Drawing.Size(47, 20);
            this.lbl_Copyright.TabIndex = 5;
            this.lbl_Copyright.Text = "Mirko";
            // 
            // tb_Description
            // 
            this.tb_Description.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.tb_Description.Location = new System.Drawing.Point(339, 132);
            this.tb_Description.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.tb_Description.Multiline = true;
            this.tb_Description.Name = "tb_Description";
            this.tb_Description.ReadOnly = true;
            this.tb_Description.Size = new System.Drawing.Size(408, 247);
            this.tb_Description.TabIndex = 7;
            // 
            // AboutForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(9F, 20F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(756, 436);
            this.ControlBox = false;
            this.Controls.Add(this.tb_Description);
            this.Controls.Add(this.lbl_Copyright);
            this.Controls.Add(this.lbl_Version);
            this.Controls.Add(this.lbl_ProductName);
            this.Controls.Add(this.btn_Close);
            this.Controls.Add(this.LogoPanel);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.Name = "AboutForm";
            this.ShowIcon = false;
            this.ShowInTaskbar = false;
            this.Text = "About ResevOps SkypeSignal";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Panel LogoPanel;
        private System.Windows.Forms.Button btn_Close;
        private System.Windows.Forms.Label lbl_ProductName;
        private System.Windows.Forms.Label lbl_Version;
        private System.Windows.Forms.Label lbl_Copyright;
        private System.Windows.Forms.TextBox tb_Description;
    }
}

