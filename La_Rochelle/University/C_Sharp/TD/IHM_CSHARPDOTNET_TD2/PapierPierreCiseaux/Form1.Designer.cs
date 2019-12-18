namespace PierrePapierCiseaux
{
    partial class Form1
    {
        /// <summary>
        /// Variable nécessaire au concepteur.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Nettoyage des ressources utilisées.
        /// </summary>
        /// <param name="disposing">true si les ressources managées doivent être supprimées ; sinon, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Code généré par le Concepteur Windows Form

        /// <summary>
        /// Méthode requise pour la prise en charge du concepteur - ne modifiez pas
        /// le contenu de cette méthode avec l'éditeur de code.
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            this.textBox1 = new System.Windows.Forms.TextBox();
            this.buttonPaper = new System.Windows.Forms.Button();
            this.buttonRock = new System.Windows.Forms.Button();
            this.buttonScissors = new System.Windows.Forms.Button();
            this.pictureBoxPaper = new System.Windows.Forms.PictureBox();
            this.pictureBoxRock = new System.Windows.Forms.PictureBox();
            this.pictureBoxScissors = new System.Windows.Forms.PictureBox();
            this.buttonWell = new System.Windows.Forms.Button();
            this.pictureBoxWell = new System.Windows.Forms.PictureBox();
            this.pictureBoxWell2 = new System.Windows.Forms.PictureBox();
            this.pictureBoxScissors2 = new System.Windows.Forms.PictureBox();
            this.pictureBoxRock2 = new System.Windows.Forms.PictureBox();
            this.pictureBoxPaper2 = new System.Windows.Forms.PictureBox();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBoxPaper)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBoxRock)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBoxScissors)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBoxWell)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBoxWell2)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBoxScissors2)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBoxRock2)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBoxPaper2)).BeginInit();
            this.SuspendLayout();
            // 
            // textBox1
            // 
            this.textBox1.Location = new System.Drawing.Point(81, 272);
            this.textBox1.Name = "textBox1";
            this.textBox1.Size = new System.Drawing.Size(136, 20);
            this.textBox1.TabIndex = 0;
            // 
            // buttonPaper
            // 
            this.buttonPaper.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("buttonPaper.BackgroundImage")));
            this.buttonPaper.Location = new System.Drawing.Point(12, 12);
            this.buttonPaper.Name = "buttonPaper";
            this.buttonPaper.Size = new System.Drawing.Size(140, 60);
            this.buttonPaper.TabIndex = 1;
            this.buttonPaper.Text = "Paper";
            this.buttonPaper.UseVisualStyleBackColor = true;
            this.buttonPaper.Click += new System.EventHandler(this.button_Click);
            // 
            // buttonRock
            // 
            this.buttonRock.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("buttonRock.BackgroundImage")));
            this.buttonRock.Location = new System.Drawing.Point(12, 78);
            this.buttonRock.Name = "buttonRock";
            this.buttonRock.Size = new System.Drawing.Size(140, 60);
            this.buttonRock.TabIndex = 2;
            this.buttonRock.Text = "Rock";
            this.buttonRock.UseVisualStyleBackColor = true;
            this.buttonRock.Click += new System.EventHandler(this.button_Click);
            // 
            // buttonScissors
            // 
            this.buttonScissors.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("buttonScissors.BackgroundImage")));
            this.buttonScissors.Location = new System.Drawing.Point(12, 144);
            this.buttonScissors.Name = "buttonScissors";
            this.buttonScissors.Size = new System.Drawing.Size(140, 60);
            this.buttonScissors.TabIndex = 3;
            this.buttonScissors.Text = "Scissors";
            this.buttonScissors.UseVisualStyleBackColor = true;
            this.buttonScissors.Click += new System.EventHandler(this.button_Click);
            // 
            // pictureBoxPaper
            // 
            this.pictureBoxPaper.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.pictureBoxPaper.Image = ((System.Drawing.Image)(resources.GetObject("pictureBoxPaper.Image")));
            this.pictureBoxPaper.Location = new System.Drawing.Point(155, 12);
            this.pictureBoxPaper.Name = "pictureBoxPaper";
            this.pictureBoxPaper.Size = new System.Drawing.Size(140, 61);
            this.pictureBoxPaper.TabIndex = 4;
            this.pictureBoxPaper.TabStop = false;
            // 
            // pictureBoxRock
            // 
            this.pictureBoxRock.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Center;
            this.pictureBoxRock.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.pictureBoxRock.Image = ((System.Drawing.Image)(resources.GetObject("pictureBoxRock.Image")));
            this.pictureBoxRock.Location = new System.Drawing.Point(155, 78);
            this.pictureBoxRock.Name = "pictureBoxRock";
            this.pictureBoxRock.Size = new System.Drawing.Size(140, 60);
            this.pictureBoxRock.TabIndex = 5;
            this.pictureBoxRock.TabStop = false;
            // 
            // pictureBoxScissors
            // 
            this.pictureBoxScissors.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.pictureBoxScissors.Image = ((System.Drawing.Image)(resources.GetObject("pictureBoxScissors.Image")));
            this.pictureBoxScissors.Location = new System.Drawing.Point(155, 144);
            this.pictureBoxScissors.Name = "pictureBoxScissors";
            this.pictureBoxScissors.Size = new System.Drawing.Size(140, 60);
            this.pictureBoxScissors.TabIndex = 6;
            this.pictureBoxScissors.TabStop = false;
            // 
            // buttonWell
            // 
            this.buttonWell.Location = new System.Drawing.Point(12, 206);
            this.buttonWell.Name = "buttonWell";
            this.buttonWell.Size = new System.Drawing.Size(140, 60);
            this.buttonWell.TabIndex = 7;
            this.buttonWell.Text = "Puits";
            this.buttonWell.UseVisualStyleBackColor = true;
            this.buttonWell.Visible = false;
            // 
            // pictureBoxWell
            // 
            this.pictureBoxWell.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.pictureBoxWell.Location = new System.Drawing.Point(155, 206);
            this.pictureBoxWell.Name = "pictureBoxWell";
            this.pictureBoxWell.Size = new System.Drawing.Size(140, 60);
            this.pictureBoxWell.TabIndex = 8;
            this.pictureBoxWell.TabStop = false;
            this.pictureBoxWell.Visible = false;
            // 
            // pictureBoxWell2
            // 
            this.pictureBoxWell2.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.pictureBoxWell2.Location = new System.Drawing.Point(301, 205);
            this.pictureBoxWell2.Name = "pictureBoxWell2";
            this.pictureBoxWell2.Size = new System.Drawing.Size(140, 60);
            this.pictureBoxWell2.TabIndex = 12;
            this.pictureBoxWell2.TabStop = false;
            this.pictureBoxWell2.Visible = false;
            // 
            // pictureBoxScissors2
            // 
            this.pictureBoxScissors2.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.pictureBoxScissors2.Image = ((System.Drawing.Image)(resources.GetObject("pictureBoxScissors2.Image")));
            this.pictureBoxScissors2.Location = new System.Drawing.Point(301, 143);
            this.pictureBoxScissors2.Name = "pictureBoxScissors2";
            this.pictureBoxScissors2.Size = new System.Drawing.Size(140, 60);
            this.pictureBoxScissors2.TabIndex = 11;
            this.pictureBoxScissors2.TabStop = false;
            this.pictureBoxScissors2.Visible = false;
            // 
            // pictureBoxRock2
            // 
            this.pictureBoxRock2.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Center;
            this.pictureBoxRock2.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.pictureBoxRock2.Image = ((System.Drawing.Image)(resources.GetObject("pictureBoxRock2.Image")));
            this.pictureBoxRock2.Location = new System.Drawing.Point(301, 77);
            this.pictureBoxRock2.Name = "pictureBoxRock2";
            this.pictureBoxRock2.Size = new System.Drawing.Size(140, 60);
            this.pictureBoxRock2.TabIndex = 10;
            this.pictureBoxRock2.TabStop = false;
            this.pictureBoxRock2.Visible = false;
            // 
            // pictureBoxPaper2
            // 
            this.pictureBoxPaper2.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.pictureBoxPaper2.Image = ((System.Drawing.Image)(resources.GetObject("pictureBoxPaper2.Image")));
            this.pictureBoxPaper2.Location = new System.Drawing.Point(301, 11);
            this.pictureBoxPaper2.Name = "pictureBoxPaper2";
            this.pictureBoxPaper2.Size = new System.Drawing.Size(140, 61);
            this.pictureBoxPaper2.TabIndex = 9;
            this.pictureBoxPaper2.TabStop = false;
            this.pictureBoxPaper2.Visible = false;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(542, 316);
            this.Controls.Add(this.pictureBoxWell2);
            this.Controls.Add(this.pictureBoxScissors2);
            this.Controls.Add(this.pictureBoxRock2);
            this.Controls.Add(this.pictureBoxPaper2);
            this.Controls.Add(this.pictureBoxWell);
            this.Controls.Add(this.buttonWell);
            this.Controls.Add(this.pictureBoxScissors);
            this.Controls.Add(this.pictureBoxRock);
            this.Controls.Add(this.pictureBoxPaper);
            this.Controls.Add(this.buttonScissors);
            this.Controls.Add(this.buttonRock);
            this.Controls.Add(this.buttonPaper);
            this.Controls.Add(this.textBox1);
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            ((System.ComponentModel.ISupportInitialize)(this.pictureBoxPaper)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBoxRock)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBoxScissors)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBoxWell)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBoxWell2)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBoxScissors2)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBoxRock2)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBoxPaper2)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox textBox1;
        private System.Windows.Forms.Button buttonPaper;
        private System.Windows.Forms.Button buttonRock;
        private System.Windows.Forms.Button buttonScissors;
        private System.Windows.Forms.PictureBox pictureBoxPaper;
        private System.Windows.Forms.PictureBox pictureBoxRock;
        private System.Windows.Forms.PictureBox pictureBoxScissors;
        private System.Windows.Forms.Button buttonWell;
        private System.Windows.Forms.PictureBox pictureBoxWell;
        private System.Windows.Forms.PictureBox pictureBoxWell2;
        private System.Windows.Forms.PictureBox pictureBoxScissors2;
        private System.Windows.Forms.PictureBox pictureBoxRock2;
        private System.Windows.Forms.PictureBox pictureBoxPaper2;
    }
}

