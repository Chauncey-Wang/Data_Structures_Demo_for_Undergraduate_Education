using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Threading;

namespace Hanoi
{
    public partial class frmMain : Form
    {
        Thread t;
        int speed = 300;
        static int count = 0;
        static Boolean firstRun = true;
        static int[] countX = new int[3];
        Label[] lbl;

        int n;
        char x, y, z;
        public frmMain()
        {
            InitializeComponent();
        }
        private int getIndex(char name)
        {
            if (name == char.Parse(txtX.Text))
            {
                return 0;
            }
            else if (name == char.Parse(txtY.Text))
            {
                return 1;
            }
            else
            {
                return 2;
            }
        }

        private void animation(int n, char x, char z)
        {
            progressBar1.Value = count;
            lbl[n - 1].Top = 90;
            Thread.Sleep(speed);
            lbl[n - 1].Left = 111 + getIndex(z) * 222 - lbl[n - 1].Width / 2 + 1;
            Thread.Sleep(speed);
            lbl[n - 1].Top = 375 - (countX[getIndex(z)]) * 5 - (countX[getIndex(z)] + 1) * 10;
            countX[getIndex(x)]--;
            countX[getIndex(z)]++;
            Thread.Sleep(speed * 2);
        }

        private void startMove()
        {
            MoveHanoi(n, x, y, z);
        }
        private void init()
        {
            if (!firstRun)
            {
                for (int i = 0; i < lbl.Length; i++)
                {
                    this.Controls.Remove(lbl[i]);
                }
            }
            progressBar1.Value = 0;
            lblStep.Text = "";
            count = 0;
            countX[1] = 0;
            countX[2] = 0;
        }
        private void MoveHanoi(int n, char x, char y, char z)
        {
            if (n == 1)
            {
                count++;
                lblStep.Text = count + "、" + x + "=>" + z;

                Thread.Sleep(speed);
                speed = 1000 - Int32.Parse(txtSpeed.Text);
                animation(n, x, z);
            }
            else
            {
                MoveHanoi(n - 1, x, z, y);
                count++;
                lblStep.Text = count + "、" + x + "=>" + z;
                speed = 1000 - Int32.Parse(txtSpeed.Text);
                animation(n, x, z);

                MoveHanoi(n - 1, y, x, z);
                if (count == progressBar1.Maximum)
                {
                    btnStart.Enabled = true;
                    btnPause.Enabled = false;
                }
            }
        }

        private void btnStart_Click(object sender, EventArgs e)
        {
            CheckForIllegalCrossThreadCalls = false;
            btnStart.Enabled = false;
            btnPause.Enabled = true;
            init();
            firstRun = false;
            this.n = Int32.Parse(txtCount.Text);
            this.x = char.Parse(txtX.Text);
            this.y = char.Parse(txtY.Text);
            this.z = char.Parse(txtZ.Text);

            lbl = new Label[n];
            for (int i = 0; i < n; i++)
            {
                lbl[i] = new Label();
                lbl[i].BackColor = Color.DarkViolet;
                lbl[i].Size = new Size(30 + i * 10, 10);
                lbl[i].Location = new Point(111 - lbl[i].Width / 2 + 1, 375 - (n - 1) * 5 - n * 10 + (i) * 5 + i * lbl[i].Height);
                this.Controls.Add(lbl[i]);
                lbl[i].BringToFront();
            }

            countX[0] = this.n;
            speed = 1000 - Int32.Parse(txtSpeed.Text);
            progressBar1.Maximum = (int)Math.Pow(2, n) - 1;
            lblA.Text = txtX.Text;
            lblB.Text = txtY.Text;
            lblC.Text = txtZ.Text;
            Thread.Sleep(speed);
            Application.DoEvents();

            t = new Thread(startMove);
            t.Start();
        }

        private void btnStop_Click(object sender, EventArgs e)
        {
            if (t.ThreadState == ThreadState.WaitSleepJoin)
            {
                t.Suspend();
                t.Resume();
            }else if(t.ThreadState == ThreadState.Suspended)
            {
                t.Resume();
                
            }
            t.Abort();
            init();
            btnStart.Enabled = true;
            btnPause.Text = "暂停";
            btnPause.Enabled = false;
        }

        private void btnPause_Click(object sender, EventArgs e)
        {
            if (t.ThreadState == ThreadState.Suspended)
            {
                t.Resume();
                btnPause.Text = "暂停";
            }
            else if (t.ThreadState == ThreadState.Running || t.ThreadState == ThreadState.WaitSleepJoin)
            {
                t.Suspend();
                btnPause.Text = "继续";
            }
        }
    }
}
