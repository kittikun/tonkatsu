// Copyright(C) 2015 kittikun
//
// This program is free software : you can redistribute it and / or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.See the
// GNU General Public License for more detailsocket.
//
// You should have received a copy of the GNU General Public License
// along with this program.If not, see <http://www.gnu.org/licenses/>.

using System;
using System.ComponentModel;
using System.Net;
using System.Net.Sockets;
using System.Text;
using UnityEngine;

public class SocketTest : MonoBehaviour
{
    private const int BUFFER_SIZE = 64;
    private const int magic_ = 'P' << 24 | 'U' << 16 | 'T' << 8 | 'E';

    private byte[] buffer_ = new byte[BUFFER_SIZE];

    private byte[] magicBuffer_;

    private Socket socket_;

    private SocketTest()
    {
        magicBuffer_ = BitConverter.GetBytes(magic_);
    }

    private static Socket ConnectSocket(string server, int port)
    {
        Socket s = null;
        IPHostEntry hostEntry = null;

        // Get host related information.
        hostEntry = Dns.GetHostEntry(server);

        // Loop through the AddressList to obtain the supported AddressFamily. This is to avoid
        // an exception that occurs when the host IP Address is not compatible with the address family
        // (typical in the IPv6 case).
        foreach (IPAddress address in hostEntry.AddressList) {
            IPEndPoint ipe = new IPEndPoint(address, port);
            Socket tempSocket =
                new Socket(ipe.AddressFamily, SocketType.Stream, ProtocolType.Tcp);

            tempSocket.Connect(ipe);

            if (tempSocket.Connected) {
                s = tempSocket;
                break;
            } else {
                continue;
            }
        }
        return s;
    }

    private void SendCompletedCallback(object sender, SocketAsyncEventArgs e)
    {
        SocketAsyncEventArgs args = new SocketAsyncEventArgs();

        args.SetBuffer(buffer_, 0, BUFFER_SIZE);

        args.Completed += ReceiveCompletedCallback;
        socket_.ReceiveAsync(args);
    }

    private bool CheckForMagic(byte[] paquet)
    {
        byte[] magicBuffer = new byte[4];

        Buffer.BlockCopy(paquet, 0, magicBuffer_, 0, magicBuffer_.Length);
        int magic = BitConverter.ToInt32(magicBuffer, 0);

        if (magic == magic_)
            return true;

        return false;
    }

    private void ReceiveCompletedCallback(object sender, SocketAsyncEventArgs e)
    {
        if (CheckForMagic(e.Buffer)) {
            string msg = Encoding.ASCII.GetString(e.Buffer, magicBuffer_.Length, e.Buffer.Length - magicBuffer_.Length);
            Debug.Log(msg);
        } else
            throw new UnityException("paquet doesn't have magic");
    }

    private void BufferFromString(string str)
    {
        if (str.Length + magicBuffer_.Length < BUFFER_SIZE) {
            Buffer.BlockCopy(magicBuffer_, 0, buffer_, 0, magicBuffer_.Length);
            Buffer.BlockCopy(str.ToCharArray(), 0, buffer_, magicBuffer_.Length, str.Length);
        } else
            throw new UnityException("buffer too small");
    }

    private void SendHeader(Paquet.Type type)
    {
        SocketAsyncEventArgs e = new SocketAsyncEventArgs();

        BufferFromString("handshake");
        Buffer.BlockCopy(magicBuffer_, 0, buffer_, 0, magicBuffer_.Length);

        // write paquet type
        buffer_[magicBuffer_.Length] = (byte)Paquet.Type.Handshake;

        e.SetBuffer(buffer_, 0, buffer_.Length);
        e.Completed += SendCompletedCallback;

        socket_.SendAsync(e);
    }

    private void Start()
    {
        Debug.Log(string.Format("IsLittleEndian : {0}", BitConverter.IsLittleEndian));

        string host = Dns.GetHostName();
        socket_ = ConnectSocket(host, 4242);

        if (socket_ == null)
            throw new UnityException("Connection failed");

        SendHeader(Paquet.Type.Handshake);
    }
}