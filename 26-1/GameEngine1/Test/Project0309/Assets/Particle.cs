using UnityEngine;

public class Particle : MonoBehaviour
{
    float start_time;
    // Start is called once before the first execution of Update after the MonoBehaviour is created
    void Start()
    {
        transform.rotation = Random.rotation;
        start_time = Time.realtimeSinceStartup;
    }

    // Update is called once per frame
    void Update()
    {
        transform.Translate(Vector3.up * Time.deltaTime);
        if (Time.realtimeSinceStartup - start_time > 2.0f) {
            DestroyGameObject();
        }
    }

    void DestroyGameObject()
    {
        Destroy(gameObject);
    }
}
