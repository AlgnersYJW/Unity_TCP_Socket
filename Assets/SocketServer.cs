using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.IO;
using System.Net.Sockets;

public class SocketServer : MonoBehaviour
{
    // Start is called before the first frame update
    StreamReader sr;

    void Start()
    {
        TcpListener listener = new TcpListener(3000);
        listener.Start();
        Socket soc = listener.AcceptSocket(); // blocks
        Stream s = new NetworkStream(soc);
        sr = new StreamReader(s);
        //sw = new StreamWriter(s);
    }

    // Update is called once per frame
    void Update()
    {
        Debug.Log(sr.ReadLine());
    }
}
