library(tuneR)
library(seewave)
library(audio)

setwd("C:/Users/marta/OneDrive/Documentos/PDIH/S5-varios-sonidos/S5-varios-sonidos")

# Leer el audio del nombre y del apellido
nombre <- readWave('nombre.wav')
apellidos <- readWave('apellidos.wav')

# Dibujar la forma de onda de ambos sonidos
# Nombre
#round(length(nombre@left) / nombre@samp.rate, 6)
plot( extractWave(nombre, from = 1, to = 110880) )

# Apellido
#round(length(apellido@left) / apellido@samp.rate, 6)
plot( extractWave(apellidos, from = 1, to = 147840) )

# Obtener la información de las cabeceras
# Nombre
nombre

# Apellido
apellidos

# Unir ambos sonidos en uno nuevo
NombreCompleto <- pastew(apellido, nombre, output="Wave")

# Dibujar la forma de onda de la señal resultante
NombreCompleto
plot( extractWave(NombreCompleto, from = 1, to = 258720) )

# Filtro de frecuencia para eliminar las frecuencias entre 10000Hz y 20000Hz 
NombreCompletoFiltrado <- bwfilter(NombreCompleto, 48000, channel = 1, from =  10000,
                                   to = 20000, bandpass = TRUE, listen = FALSE, output = "Wave")

NombreCompletoFiltrado
plot( extractWave(NombreCompletoFiltrado, from = 1, to = 258720) )

# Almacenar la señal obtenida como un fichero WAV denominado “mezcla.wav”
writeWave(NombreCompletoFiltrado, file.path("mezcla.wav"))

# Cargar un nuevo archivo de sonido
perro <- readWave('perro.wav')
  
# Aplicarle eco
perroEco <- echo(perro, f=22050, amp=c(0.8,0.4,0.2), delay=c(1,2,3), output="Wave")
perroEco@left <- 10000 * perroEco@left

# Darle lavuelta al sonido
perroEcoAlreves <- revw(perroEco, output="Wave")

# Almacenar la señal obtenida como un fichero WAV denominado “alreves.wav”
writeWave(perroEcoAlreves, file.path("alreves.wav"))
