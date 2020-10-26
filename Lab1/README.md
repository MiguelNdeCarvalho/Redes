# Questions

Chose the adequate tools (install them if necessary) and answer each one of the questions

1. Obtain the IP address of the host "www.uevora.pt".

2. Check if that host is alive on the network.

3. What is the network latency between your host and "www.uevora.pt"?

4. What is the network latency between your host and "www.google.com"?

5. Which other network hosts are in the path between your host and

    1. www.uevora.pt?

    2. www.google.com?

    3. www.baidu.com?

Submit your answers in the forum of this lab, in a post withtext message, with

#N Number of the question - Name of the tool .

# Answers

1. NSLookup

`IP: 193.136.216.21`

2. ping

```bash
64 bytes from arachne.uevora.pt (193.136.216.21): icmp_seq=1 ttl=56 time=32.3 ms
```

3. ping

```bash
--- arachne.uevora.pt ping statistics ---
6 packets transmitted, 6 received, 0% packet loss, time 13ms
rtt min/avg/max/mdev = 23.121/24.881/32.261/3.304 ms
```

4. Ping

```bash
--- www.google.pt ping statistics ---
6 packets transmitted, 6 received, 0% packet loss, time 13ms
rtt min/avg/max/mdev = 19.450/25.866/37.584/6.120 ms
```

5. Traceroute

    1. Traceroute (www.uevora.pt)

    ```bash
    1  192.168.1.1 (192.168.1.1)  0.637 ms  0.587 ms  0.511 ms
    2  2.96.54.77.rev.vodafone.pt (77.54.96.2)  10.644 ms  10.599 ms  10.974 ms
    3  113.41.30.213.rev.vodafone.pt (213.30.41.113)  16.129 ms  16.555 ms  17.524 ms
    4  FCCN.AS1930.gigapix.pt (193.136.251.1)  24.053 ms  23.908 ms  22.009 ms
    5  Router30.Lisboa.fccn.pt (194.210.6.102)  24.010 ms  22.674 ms
    6  Router13.Lisboa.fccn.pt (194.210.6.111)  24.784 ms  21.150 ms  22.973 ms
    7  UEvora.Evora.fccn.pt (193.136.1.18)  24.886 ms  25.213 ms  25.110 ms
    ```

    2. Traceroute (www.google.com)

    ```bash
    1  192.168.1.1 (192.168.1.1)  0.539 ms  0.585 ms  0.395 ms
    2  2.96.54.77.rev.v@sfodafone.pt (77.54.96.2)  12.286 ms  11.729 ms  12.168 ms
    3  24.50.174.83.rev.vodafone.pt (83.174.50.24)  14.021 ms  14.319 ms  12.941 ms
    4  142.250.161.112 (142.250.161.112)  14.204 ms  14.157 ms  14.109 ms
    5  74.125.245.101 (74.125.245.101)  14.338 ms  14.261 ms 74.125.245.84 (74.125.245.84)  14.254 ms
    6  72.14.239.53 (72.14.239.53)  23.980 ms  22.400 ms 66.249.94.87 (66.249.94.87)  22.294 ms
    7  74.125.242.177 (74.125.242.177)  22.858 ms  19.942 ms 74.125.242.161 (74.125.242.161)  21.536 ms
    8  74.125.253.197 (74.125.253.197)  22.774 ms 74.125.253.199 (74.125.253.199)  20.229 ms  22.682 ms
    9  mad07s09-in-f4.1e100.net (172.217.17.4)  21.594 ms  21.224 ms  22.710 ms
    ```

    3. Traceroute (www.baidu.com)

    ```bash
    1  192.168.1.1 (192.168.1.1)  0.489 ms  0.453 ms  0.512 ms
    2  2.96.54.77.rev.vodafone.pt (77.54.96.2)  10.242 ms  11.087 ms  11.267 ms
    3  107.41.30.213.rev.vodafone.pt (213.30.41.107)  12.506 ms  11.975 ms  13.707 ms
    4  ae5-100.ucr1.lis.cw.net (195.10.57.9)  13.989 ms  13.945 ms  15.317 ms
    5  80.231.158.132 (80.231.158.132)  13.751 ms  14.017 ms  13.938 ms
    6  80.231.158.30 (80.231.158.30)  176.913 ms  174.202 ms  171.873 ms
    7  *
    8  if-ae-4-2.tcore2.n0v-newyork.as6453.net (80.231.131.158)  175.308 ms  175.044 ms  176.573 ms
    9  if-ae-2-2.tcore1.n0v-newyork.as6453.net (216.6.90.21)  175.006 ms if-ae-36-2.tcore1.sqn-sanjose.as6453.net (63.243.128.167)  170.642 ms if-ae-2-2.tcore1.n0v-newyork.as6453.net (216.6.90.21)  174.771 ms
    10  if-ae-18-2.tcore2.sv1-santaclara.as6453.net (63.243.205.73)  171.721 ms if-ae-18-4.tcore2.sv1-santaclara.as6453.net (63.243.205.13)  171.773 ms  170.309 ms
    11  if-ae-0-2.tcore1.sqn-sanjose.as6453.net (63.243.128.31)  183.306 ms 209.58.86.30 (209.58.86.30)  177.958 ms if-ae-36-2.tcore1.sqn-sanjose.as6453.net (63.243.128.167)  173.827 ms
    12  180.76.0.54 (180.76.0.54)  274.713 ms  272.796 ms  273.246 ms
    13  180.76.0.53 (180.76.0.53)  268.269 ms  268.389 ms 209.58.86.30 (209.58.86.30)  180.856 ms
    14  180.76.0.7 (180.76.0.7)  267.784 ms  267.915 ms  268.916 ms
    15  180.76.0.53 (180.76.0.53)  272.115 ms
    16  180.76.0.5 (180.76.0.5)  272.371 ms
    ```
