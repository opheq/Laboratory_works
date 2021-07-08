using System;
using System.Windows;
using System.IO;
using System.Text;

namespace Viginere_Cipher
{
    /// <summary>
    /// Логика взаимодействия для MainWindow.xaml
    /// </summary>
    public partial class DeCipherWindow : Window
    {

        const string letters = "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ0123456789 ";

        int TextOrder;
        int tempKey;
        int tempText;
        string KeyResult;
        public DeCipherWindow()
        {
            InitializeComponent();
            ReadText();
            ReadKey();
        }
        private async void ReadText()
        {
            var Rand = new Random();
            TextOrder = Rand.Next(0, 10);
            tempText = 0;
            string filename = "Texts.txt";
            char[] result;
            StringBuilder builder = new StringBuilder();

            using (StreamReader reader = File.OpenText(filename))
            {
                result = new char[reader.BaseStream.Length];
                await reader.ReadAsync(result, 0, (int)reader.BaseStream.Length);
            }

            foreach (char c in result)
            {
             
                if (c.Equals('\n') && tempText > TextOrder)
                {
                    break;
                }
                if (tempText == TextOrder)
                    builder.Append(c);
                if (c.Equals('\n'))
                {
                    tempText++;
                }
            }
           // Analysis.Text = TextOrder.ToString();
            Text.Text = builder.ToString();
        }

        private async void ReadKey()
        {
            string filename = "Keys.txt";
            char[] result;
            tempKey = 0;
            StringBuilder builder = new StringBuilder();

            using (StreamReader reader = File.OpenText(filename))
            {
                result = new char[reader.BaseStream.Length];
                await reader.ReadAsync(result, 0, (int)reader.BaseStream.Length);
            }

            foreach (char c in result)
            {

                if (c.Equals('\n') && tempKey > TextOrder)
                {
                    break;
                }
                if (tempKey == TextOrder)
                    builder.Append(c);
                if (c.Equals('\n'))
                {
                    tempKey++;
                }
            }
            
            Analysis.Text = builder.ToString();
            KeyResult = builder.ToString();
        }

        //генерация повторяющегося пароля
        private string GetRepeatKey(string s, int n)
            {
                var p = s;
                while (p.Length < n)
                {
                    p += p;
                }

                return p.Substring(0, n);
            }

            private string Vigenere(string text, string password, bool encrypting = true)
            {
                var gamma = GetRepeatKey(password, text.Length);
                var retValue = "";
                var q = letters.Length;

                for (int i = 0; i < text.Length; i++)
                {
                    var letterIndex = letters.IndexOf(text[i]);
                    var codeIndex = letters.IndexOf(gamma[i]);
                    if (letterIndex < 0)
                    {
                        //если буква не найдена, добавляем её в исходном виде
                        retValue += text[i].ToString();
                    }
                    else
                    {
                        retValue += letters[(q + letterIndex + ((encrypting ? 1 : -1) * codeIndex)) % q].ToString();
                    }
                }

                return retValue;
            }

            //шифрование текста
            public string Encrypt(string plainMessage, string password)
                => Vigenere(plainMessage, password);

            //дешифрование текста
            public string Decrypt(string encryptedMessage, string password)
                => Vigenere(encryptedMessage, password, false);
        private void DecryptKey_Click(object sender, RoutedEventArgs e)
        {
            if (Key.Text == null) return;
            Text.Text = Decrypt(Text.Text.ToUpper(), Key.Text.ToUpper());
            EncryptKey.IsEnabled = true;
            DecryptKey.IsEnabled = false;
            Key.IsEnabled = false;
            if (Key.Text.ToUpper() + '\r' + '\n' == KeyResult.ToUpper()) MessageBox.Show("Лабораторная работа выполнена!");
        }
        private void EncryptKey_Click(object sender, RoutedEventArgs e)
        {
            if (Key.Text == null) return;
            Text.Text = Encrypt(Text.Text.ToUpper(), Key.Text.ToUpper());
            EncryptKey.IsEnabled = false;
            DecryptKey.IsEnabled = true;
            Key.IsEnabled = true;
        }

    }
}
