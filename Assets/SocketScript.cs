using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.IO;
using System.Net.Sockets;

public class SocketScript : MonoBehaviour
{

    StreamWriter sw;
    TcpClient client;
    Stream s;

    // Start is called before the first frame update
    void Start()
    {
        client = new TcpClient("localhost", 3000);
        s = client.GetStream();
        sw = new StreamWriter(s);

    }

    // Update is called once per frame
    void Update()
    {
        //client.Send(data, data.Length);
        sw.WriteLine("test!");
    }
}
