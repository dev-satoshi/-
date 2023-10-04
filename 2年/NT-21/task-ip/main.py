def calculate_network_mask(ip_address, subnet_mask):
    # IPアドレスとサブネットマスクをオクテットに分割する
    ip_octets = ip_address.split(".")
    subnet_octets = subnet_mask.split(".")

    # ネットワークマスクオクテットを格納するために空のリストを初期化する
    network_mask_octets = []

    # IPとサブネットマスクの各オクテットに対してビットごとのAND演算を実行する
    for i in range(4):
        network_mask_octet = int(ip_octets[i]) & int(subnet_octets[i])
        network_mask_octets.append(str(network_mask_octet))

    # ネットワークマスクオクテットを結合し、結果を返す
    network_mask = ".".join(network_mask_octets)
    return network_mask


# IPアドレスとサブネットマスクを入力
ip_address1 = input("クライアントIP： ")
subnet_mask1 = input("サブネット： ")
ip_address2 = input("サーバーIP： ")
subnet_mask2 = input("サブネット： ")

# ネットワークマスクを計算して出力する
client_network_mask1 = calculate_network_mask(ip_address1, subnet_mask1)
client_network_mask2 = calculate_network_mask(ip_address2, subnet_mask1)
server_network_mask1 = calculate_network_mask(ip_address1, subnet_mask2)
server_network_mask2 = calculate_network_mask(ip_address2, subnet_mask2)

# クライアントとサーバーのネットワークマスクを比較し、テキストの色を設定する
if client_network_mask1 == client_network_mask2 == server_network_mask1 == server_network_mask2:
    color = "\x1b[33m"  # Yellow
elif client_network_mask1 == client_network_mask2:
    color = "\x1b[34m"  # Blue
else:
    color = "\x1b[31m"  # Red

# 出力後に文字色をリセット
reset_color = "\x1b[0m"

print(f"クライアント視点: {color}{client_network_mask1}  {client_network_mask2}{reset_color}")
print(f"サーバー視点: {color}{server_network_mask1}  {server_network_mask2}{reset_color}")
