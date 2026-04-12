using UnityEngine;

public class CarMoveFunction : MonoBehaviour
{
    float ForwardSpeed = 0;
    float Angle = 0;
    // Start is called once before the first execution of Update after the MonoBehaviour is created
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        if (Input.GetKey(KeyCode.W))
        {
            if (ForwardSpeed < 10.0f)
                ForwardSpeed += 0.2f;
            else
                ForwardSpeed = 10.0f;
            print("Input W key");
        }
        else if (Input.GetKeyUp(KeyCode.W))
        {
            ForwardSpeed = 0;
        }

        if (Input.GetKey(KeyCode.D))
        {
            if (Angle < 45.0f)
                Angle += 0.5f;
            else
                Angle = 45.0f;
        }
        else if (Input.GetKeyUp(KeyCode.D))
        {
            Angle = 0;
        }

        if (Input.GetKey(KeyCode.A))
        {
            if (Angle > -45.0f)
                Angle -= 0.5f;
            else
                Angle = -45.0f;
        }
        else if (Input.GetKeyUp(KeyCode.A))
        {
            Angle = 0;
        }
        
        transform.Rotate(Vector3.up * Angle * Time.deltaTime);
        transform.Translate(Vector3.forward * ForwardSpeed * Time.deltaTime);
    }
}
