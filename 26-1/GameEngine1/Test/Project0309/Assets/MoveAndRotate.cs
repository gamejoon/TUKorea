using UnityEngine;
using UnityEngine.UIElements;

public class MoveAndRotate : MonoBehaviour
{
    private MeshRenderer r;
    private Collider c;

    // Start is called once before the first execution of Update after the MonoBehaviour is created
    void Start()
    {
        r = GetComponent<MeshRenderer>();
        c = GetComponent<Collider>();
    }

    // Update is called once per frame
    void Update()
    {
        
    }

    private void OnMouseDown()
    {
        print("OnMouseDown");
        r.material.color = Color.yellow;
    }
}
