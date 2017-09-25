using UnityEngine;
using System.Collections;
using System.IO.Ports;
using System.Threading;

public class Arduino_Control02 : MonoBehaviour {
    public static SerialPort sp = new SerialPort("COM2", 9600);
    float timepassed = 0.0f;
    public Transform Pos;
    public float num = 1.0f;    
    public float h = 0.0f;
    public float v = 0.0f;
    public Transform tr;
    public float moveSpeed = 10.0f;
    public int change;
    // Use this for initialization
    void Start () {
        OpenConnection();
        tr = GetComponent<Transform>();
        change = 1;
    }

    // Update is called once per frame
    void Update()
    {
        /*message2 = sp.ReadLine();
        print(message2);*/
       // h = Input.GetAxis("Horizontal");
        //v = Input.GetAxis("Vertical");


        //tr.Translate(Vector3.forward * moveSpeed * v * Time.deltaTime, Space.Self);
        //tr.Translate(Vector3.right * moveSpeed * h * Time.deltaTime, Space.Self);
        Debug.DrawRay(Pos.position, Pos.forward * 10.0f, Color.green);
        RaycastHit hit;
        if (Physics.Raycast(Pos.position, Pos.forward, out hit, 5.0f))
        {
            if (hit.collider.tag == "Door1" && change == 1)
            {
                print("true_door1");
                sp.Write("r");
                change = 0;
            }
            else if(hit.collider.tag == "Door2" && change == 1)
            {
                print("true_door2");
                sp.Write("g");
                change = 0;
            }
            else if (hit.collider.tag == "Door3" && change == 1)
            {
                print("true_door3");
                sp.Write("b");
                change = 0;
            }
            else if(hit.collider.tag == "House" && change == 0)
            {
                print("none");
                sp.Write("n");
                change = 1;
            }
        }
        else
        {   if(change == 0)
            {
                print("nothing");
                sp.Write("n");
                change = 1;
            }
            
        }
    }

    public void OpenConnection()
    {
        if(sp != null)
        {
            if(sp.IsOpen)
            {
                sp.Close();
                print("Closing port");
            }
            else
            {
                sp.Open();
                sp.ReadTimeout = 15;        //잠시 멈추게하는? x밀리초동안?
                print("Port open!");
            }
        }
        else
        {
            if(sp.IsOpen)
            {
                print("Port is already opened");
            }
            else
            {
                print("Port == null");
            }
        }
    }

    void OnApplicationQuit()
    {
        sp.Close();
    }
}
