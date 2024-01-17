function login (){
    const namaFile = 'Password.txt';
    pass = document.getElementById('pin').value;

        // Buat objek XMLHttpRequest
        const xhr = new XMLHttpRequest();

        // Set up request
        xhr.open('GET', namaFile, true);

        // Mengatur callback ketika permintaan selesai
        xhr.onload = function() {
            if (xhr.status === 200) {
                // Data berhasil dibaca
                if(pass == xhr.responseText){
                    alert('Pin Benar');
                    window.location = "mainControl.html"
                }else{
                    if(pass == ''){
                        alert('Masukan Pin');
                    }else{
                        alert('Pin Salah');
                    }
                }

            } else {
                // Terjadi kesalahan
                console.error('Gagal membaca file:', xhr.statusText);
            }
        };

        // Mengatur callback untuk kesalahan jaringan
        xhr.onerror = function() {
            console.error('Kesalahan jaringan');
        };

        // Kirim permintaan
        xhr.send();
}
