using UnityEngine;

public class ClickAndDestroy : MonoBehaviour
{
    public GameObject particle;
    float start_time;
    bool MouseDown = false;
    private MeshRenderer r;
    // Start is called once before the first execution of Update after the MonoBehaviour is created
    void Start()
    {
        r = GetComponent<MeshRenderer>();
    }

    // Update is called once per frame
    void Update()
    {
        if (MouseDown && Time.realtimeSinceStartup - start_time > 1.0f)
        {
            DestroyGameObject();
        }
    }

    private void OnMouseDown()
    {
        if (MouseDown != true)
        {
            for (int i = 0; i < 100; i++)
            {
                Instantiate(particle, transform.position, transform.rotation);
                print("instantiate " + i);
            }
            r.material.color = Color.yellow;
            start_time = Time.realtimeSinceStartup;
            MouseDown = true;
        }
    }

    void DestroyGameObject()
    {
        Destroy(gameObject);
    }
}
