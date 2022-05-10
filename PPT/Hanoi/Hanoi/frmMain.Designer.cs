namespace Hanoi
{
    partial class frmMain
    {
        /// <summary>
        /// 必需的设计器变量。
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 清理所有正在使用的资源。
        /// </summary>
        /// <param name="disposing">如果应释放托管资源，为 true；否则为 false。</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows 窗体设计器生成的代码

        /// <summary>
        /// 设计器支持所需的方法 - 不要修改
        /// 使用代码编辑器修改此方法的内容。
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(frmMain));
            this.label1 = new System.Windows.Forms.Label();
            this.txtSpeed = new System.Windows.Forms.TextBox();
            this.progressBar1 = new System.Windows.Forms.ProgressBar();
            this.lblStep = new System.Windows.Forms.Label();
            this.lblC = new System.Windows.Forms.Label();
            this.lblB = new System.Windows.Forms.Label();
            this.lblA = new System.Windows.Forms.Label();
            this.LineC = new System.Windows.Forms.Label();
            this.LineB = new System.Windows.Forms.Label();
            this.LineA = new System.Windows.Forms.Label();
            this.btnStart = new System.Windows.Forms.Button();
            this.lblZ = new System.Windows.Forms.Label();
            this.txtZ = new System.Windows.Forms.TextBox();
            this.lblY = new System.Windows.Forms.Label();
            this.lblX = new System.Windows.Forms.Label();
            this.lblCount = new System.Windows.Forms.Label();
            this.txtY = new System.Windows.Forms.TextBox();
            this.txtX = new System.Windows.Forms.TextBox();
            this.txtCount = new System.Windows.Forms.TextBox();
            this.btnPause = new System.Windows.Forms.Button();
            this.btnStop = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(93, 13);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(41, 12);
            this.label1.TabIndex = 37;
            this.label1.Text = "速度：";
            // 
            // txtSpeed
            // 
            this.txtSpeed.Location = new System.Drawing.Point(135, 9);
            this.txtSpeed.Name = "txtSpeed";
            this.txtSpeed.Size = new System.Drawing.Size(36, 21);
            this.txtSpeed.TabIndex = 36;
            this.txtSpeed.Text = "700";
            // 
            // progressBar1
            // 
            this.progressBar1.Location = new System.Drawing.Point(-1, 410);
            this.progressBar1.Name = "progressBar1";
            this.progressBar1.Size = new System.Drawing.Size(674, 12);
            this.progressBar1.TabIndex = 35;
            // 
            // lblStep
            // 
            this.lblStep.Font = new System.Drawing.Font("宋体", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.lblStep.Location = new System.Drawing.Point(484, 19);
            this.lblStep.Name = "lblStep";
            this.lblStep.Size = new System.Drawing.Size(176, 24);
            this.lblStep.TabIndex = 34;
            this.lblStep.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            // 
            // lblC
            // 
            this.lblC.Font = new System.Drawing.Font("宋体", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.lblC.Location = new System.Drawing.Point(547, 65);
            this.lblC.Name = "lblC";
            this.lblC.Size = new System.Drawing.Size(19, 19);
            this.lblC.TabIndex = 33;
            this.lblC.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // lblB
            // 
            this.lblB.Font = new System.Drawing.Font("宋体", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.lblB.Location = new System.Drawing.Point(325, 65);
            this.lblB.Name = "lblB";
            this.lblB.Size = new System.Drawing.Size(19, 19);
            this.lblB.TabIndex = 32;
            this.lblB.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // lblA
            // 
            this.lblA.Font = new System.Drawing.Font("宋体", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.lblA.Location = new System.Drawing.Point(103, 65);
            this.lblA.Name = "lblA";
            this.lblA.Size = new System.Drawing.Size(19, 19);
            this.lblA.TabIndex = 31;
            this.lblA.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // LineC
            // 
            this.LineC.BackColor = System.Drawing.Color.Blue;
            this.LineC.Location = new System.Drawing.Point(555, 109);
            this.LineC.Name = "LineC";
            this.LineC.Size = new System.Drawing.Size(3, 270);
            this.LineC.TabIndex = 30;
            // 
            // LineB
            // 
            this.LineB.BackColor = System.Drawing.Color.Green;
            this.LineB.Location = new System.Drawing.Point(333, 109);
            this.LineB.Name = "LineB";
            this.LineB.Size = new System.Drawing.Size(3, 270);
            this.LineB.TabIndex = 29;
            // 
            // LineA
            // 
            this.LineA.BackColor = System.Drawing.Color.Red;
            this.LineA.Location = new System.Drawing.Point(111, 109);
            this.LineA.Name = "LineA";
            this.LineA.Size = new System.Drawing.Size(3, 270);
            this.LineA.TabIndex = 28;
            // 
            // btnStart
            // 
            this.btnStart.Location = new System.Drawing.Point(277, 20);
            this.btnStart.Name = "btnStart";
            this.btnStart.Size = new System.Drawing.Size(54, 23);
            this.btnStart.TabIndex = 27;
            this.btnStart.Text = "开始！";
            this.btnStart.UseVisualStyleBackColor = true;
            this.btnStart.Click += new System.EventHandler(this.btnStart_Click);
            // 
            // lblZ
            // 
            this.lblZ.AutoSize = true;
            this.lblZ.Location = new System.Drawing.Point(178, 40);
            this.lblZ.Name = "lblZ";
            this.lblZ.Size = new System.Drawing.Size(41, 12);
            this.lblZ.TabIndex = 26;
            this.lblZ.Text = "目标：";
            // 
            // txtZ
            // 
            this.txtZ.Location = new System.Drawing.Point(220, 36);
            this.txtZ.Name = "txtZ";
            this.txtZ.Size = new System.Drawing.Size(22, 21);
            this.txtZ.TabIndex = 25;
            this.txtZ.Text = "C";
            // 
            // lblY
            // 
            this.lblY.AutoSize = true;
            this.lblY.Location = new System.Drawing.Point(94, 40);
            this.lblY.Name = "lblY";
            this.lblY.Size = new System.Drawing.Size(41, 12);
            this.lblY.TabIndex = 24;
            this.lblY.Text = "辅助：";
            // 
            // lblX
            // 
            this.lblX.AutoSize = true;
            this.lblX.Location = new System.Drawing.Point(12, 40);
            this.lblX.Name = "lblX";
            this.lblX.Size = new System.Drawing.Size(41, 12);
            this.lblX.TabIndex = 23;
            this.lblX.Text = "起始：";
            // 
            // lblCount
            // 
            this.lblCount.AutoSize = true;
            this.lblCount.Location = new System.Drawing.Point(12, 13);
            this.lblCount.Name = "lblCount";
            this.lblCount.Size = new System.Drawing.Size(41, 12);
            this.lblCount.TabIndex = 22;
            this.lblCount.Text = "数量：";
            // 
            // txtY
            // 
            this.txtY.Location = new System.Drawing.Point(136, 36);
            this.txtY.Name = "txtY";
            this.txtY.Size = new System.Drawing.Size(22, 21);
            this.txtY.TabIndex = 21;
            this.txtY.Text = "B";
            // 
            // txtX
            // 
            this.txtX.Location = new System.Drawing.Point(54, 36);
            this.txtX.Name = "txtX";
            this.txtX.Size = new System.Drawing.Size(22, 21);
            this.txtX.TabIndex = 20;
            this.txtX.Text = "A";
            // 
            // txtCount
            // 
            this.txtCount.Location = new System.Drawing.Point(54, 9);
            this.txtCount.Name = "txtCount";
            this.txtCount.Size = new System.Drawing.Size(33, 21);
            this.txtCount.TabIndex = 19;
            this.txtCount.Text = "3";
            // 
            // btnPause
            // 
            this.btnPause.Enabled = false;
            this.btnPause.Location = new System.Drawing.Point(337, 20);
            this.btnPause.Name = "btnPause";
            this.btnPause.Size = new System.Drawing.Size(54, 23);
            this.btnPause.TabIndex = 38;
            this.btnPause.Text = "暂停";
            this.btnPause.UseVisualStyleBackColor = true;
            this.btnPause.Click += new System.EventHandler(this.btnPause_Click);
            // 
            // btnStop
            // 
            this.btnStop.Location = new System.Drawing.Point(397, 20);
            this.btnStop.Name = "btnStop";
            this.btnStop.Size = new System.Drawing.Size(54, 23);
            this.btnStop.TabIndex = 39;
            this.btnStop.Text = "停止";
            this.btnStop.UseVisualStyleBackColor = true;
            this.btnStop.Click += new System.EventHandler(this.btnStop_Click);
            // 
            // frmMain
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(672, 422);
            this.Controls.Add(this.btnStop);
            this.Controls.Add(this.btnPause);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.txtSpeed);
            this.Controls.Add(this.progressBar1);
            this.Controls.Add(this.lblStep);
            this.Controls.Add(this.lblC);
            this.Controls.Add(this.lblB);
            this.Controls.Add(this.lblA);
            this.Controls.Add(this.LineC);
            this.Controls.Add(this.LineB);
            this.Controls.Add(this.LineA);
            this.Controls.Add(this.btnStart);
            this.Controls.Add(this.lblZ);
            this.Controls.Add(this.txtZ);
            this.Controls.Add(this.lblY);
            this.Controls.Add(this.lblX);
            this.Controls.Add(this.lblCount);
            this.Controls.Add(this.txtY);
            this.Controls.Add(this.txtX);
            this.Controls.Add(this.txtCount);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.MaximizeBox = false;
            this.Name = "frmMain";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Hanoi";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox txtSpeed;
        private System.Windows.Forms.ProgressBar progressBar1;
        private System.Windows.Forms.Label lblStep;
        private System.Windows.Forms.Label lblC;
        private System.Windows.Forms.Label lblB;
        private System.Windows.Forms.Label lblA;
        private System.Windows.Forms.Label LineC;
        private System.Windows.Forms.Label LineB;
        private System.Windows.Forms.Label LineA;
        private System.Windows.Forms.Button btnStart;
        private System.Windows.Forms.Label lblZ;
        private System.Windows.Forms.TextBox txtZ;
        private System.Windows.Forms.Label lblY;
        private System.Windows.Forms.Label lblX;
        private System.Windows.Forms.Label lblCount;
        private System.Windows.Forms.TextBox txtY;
        private System.Windows.Forms.TextBox txtX;
        private System.Windows.Forms.TextBox txtCount;
        private System.Windows.Forms.Button btnPause;
        private System.Windows.Forms.Button btnStop;
    }
}

