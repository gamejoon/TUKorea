using UnityEngine;

public class rotate : MonoBehaviour
{
    private float rotateSpeed = 0.5f;
    public float moveSpeed = 0.01f;
    // Start is called once before the first execution of Update after the MonoBehaviour is created
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        print("Start:: transform =" + transform.position);
        print("Move Speed is " + moveSpeed + ".");
    }

    private void OnBecameVisible()
    {

    }

    private void OnMouseDown()
    {

    }

    private void OnCollisionEnter(Collision collision)
    {

    }
}
